import gumath
import llvmlite.ir

import numba

from . import libndtypes, libxnd, shared


def register_kernel(signatures):
    name = shared.random_kernel_name()
    signatures = (signatures,) if isinstance(signatures, str) else signatures

    def inner(fn):
        for signature in signatures:
            kernel = register_kernel_direct(name, signature)(
                jit_and_wrap(signature)(fn)
            )
        return kernel

    return inner


def jit_and_wrap(signature):
    """
    Generates stack types from the signature and jit compiles a kernel that takes in those stack types

    >>> @register_kernel_direct("some name", "int64, int64 -> int64")
    ... @jit_and_register("int64, int64 -> int64")
    ... def add_kernel(a, b, ret):
    ...     ret[()] = a.value + b.value
    >>> add_kernel(xnd.xnd(1), xnd.xnd(2))
    xnd(3, type='int64')
    """

    stack_types = tuple(map(libxnd.XndWrapperType, shared.sig_to_stack(signature)))

    def inner(fn):
        dispatcher = numba.njit(stack_types)(fn)

        return wrap_kernel_dispatcher(len(stack_types))(dispatcher)

    return inner


def wrap_kernel_dispatcher(n_args):
    """
    Returns a new dispatcher that is suitable to be registered with `register_kernel_direct`.

    The original dispatcher must have wrapper types specified explicitly so the

    Use like:

        @register_kernel_direct("some name", "int64, 10 * int64 -> int64")
        @wrap_kernel_dispatcher(3)
        @njit(XndWrapperType(ndt("int64"))(...))
        def something(a, b, ret):
            ret[()] = a + b[0]
    """

    # TODO: Catch exceptions and return -1
    def inner(dispatcher):
        if n_args == 0:

            def fn(stack, ctx):
                dispatcher()
                return 0

        elif n_args == 1:

            def fn(stack, ctx):
                dispatcher(stack[0])
                return 0

        elif n_args == 2:

            def fn(stack, ctx):
                dispatcher(stack[0], stack[1])
                return 0

        elif n_args == 3:

            def fn(stack, ctx):
                dispatcher(stack[0], stack[1], stack[2])
                return 0

        elif n_args == 4:

            def fn(stack, ctx):
                dispatcher(stack[0], stack[1], stack[2], stack[3])
                return 0

        else:
            raise NotImplementedError("Too many args")

        return numba.njit(fn)

    return inner


def register_kernel_direct(name, signature):
    """
    Registers a Gumath kernel that calls the Numba dispatcher. The function should take in a stack of
    xnd types a context type, just like if you were writing a kernel in C

    Like:

        @register_kernel_direct("some_name", "... * ... -> ...")
        @njit
        def something(stack, ctx):
            x, y, res = stack[0], stack[1], stack[2]
    """

    def inner(dispatcher):
        numba_sig = numba.types.int32(libxnd.xnd_type, libndtypes.ndt_context_type)
        entry_point = dispatcher.compile(numba_sig)
        cres = [
            cres
            for cres in dispatcher.overloads.values()
            if cres.entry_point == entry_point
        ][0]

        return gumath.unsafe_add_kernel(
            name=name, sig=signature, ptr=build_kernel_wrapper(cres), tag="Xnd"
        )

    return inner


# based on
# https://github.com/Quansight/numba/blob/da7669f34a356d6b0468edcab604ce24be7f7ce8/numba/plures/llvm.py#L51
# TODO: Maybe this can made shorter? Reuse some existing numba functions?
def build_kernel_wrapper(cres):
    """
    Returns a pointer to a llvm function that can be used as an xnd kernel.
    Like build_ufunc_wrapper
    """
    ctx = cres.target_context
    library = cres.library
    signature = cres.signature
    # envptr = cres.environment.as_pointer(ctx)
    # setup the module and jitted function
    wrapperlib = ctx.codegen().create_library("gumath_wrapper")
    wrapper_module = wrapperlib.create_ir_module("")

    func_type = ctx.call_conv.get_function_type(signature.return_type, signature.args)
    func = wrapper_module.add_function(func_type, name=cres.fndesc.llvm_func_name)
    func.attributes.add("alwaysinline")

    # create xnd kernel function
    # we will return a pointer to this function
    wrapper = wrapper_module.add_function(
        llvmlite.ir.FunctionType(
            shared.i32, (shared.ptr(libxnd.xnd_t), shared.ptr(libndtypes.ndt_context_t))
        ),
        "__gumath__." + func.name,
    )
    builder = llvmlite.ir.IRBuilder(wrapper.append_basic_block("entry"))

    # called numba jitted function on inputs
    status, retval = ctx.call_conv.call_function(
        builder, func, signature.return_type, signature.args, wrapper.args  # env=envptr
    )

    with builder.if_then(status.is_error, likely=False):
        # return -1 on failure
        builder.ret(llvmlite.ir.Constant(shared.i32, -1))

    builder.ret(retval)

    wrapperlib.add_ir_module(wrapper_module)
    wrapperlib.add_linking_library(library)
    return wrapperlib.get_pointer_to_function(wrapper.name)
