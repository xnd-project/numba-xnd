import functools
import inspect

import llvmlite.ir

import numba.extending
import numba.types
import numba.typing.templates


def llvm_type_from_numba_type(numba_type):
    datamodel = numba.datamodel.registry.default_manager[numba_type]
    return datamodel.get_value_type()


def dispatcher_cres(dispatcher, sig):
    """
    Compiles the dispatcher for `sig` and return the resulting compilation result.
    """
    entry_point = dispatcher.compile(sig)
    return [
        cres
        for cres in dispatcher.overloads.values()
        if cres.entry_point == entry_point
    ][0]


def overload_any(func):
    """
    Like `numba.extending.overload` but works for things like `getitem`, etc.

    Used likes `generated_jit`:

        @overload_any("getitem")
        def getitem_const(val, i):
            if val.value == "hi":
                return lambda val, i: i
            elif val.value == "there":
                return lambda val, i: -i
    """

    def inner(overload_func):
        # lower dispatcher based on `numba.typing.templates._OverloadMethodTemplate.do_class_init`
        dispatcher = numba.generated_jit(nopython=True)(overload_func)

        @numba.extending.type_callable(func)
        def type_inner(context):
            # need to pass in `dispatcher` or get "underlying object has vanished"
            def typer(*args, dispatcher=dispatcher):
                try:
                    cres = dispatcher_cres(dispatcher, args)
                except TypeError:  # None returned by overloaded function
                    return
                dispatcher.targetctx.insert_user_function(
                    func, cres.fndesc, [cres.library]
                )
                return cres.signature.return_type

            return typer

    return inner


def create_tuple_creator(f, n):
    """
    To work around https://github.com/numba/numba/issues/2771
    """
    assert n > 0
    f = numba.njit(f)

    creator = functools.reduce(
        lambda creator, i: numba.njit(lambda args: creator(args) + (f(i, *args),)),
        range(1, n),
        numba.njit(lambda args: (f(0, *args),)),
    )

    return numba.njit(lambda *args: creator(args))
