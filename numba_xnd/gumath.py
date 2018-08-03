import gumath
import llvmlite.ir
import ndtypes

import numba

from . import libndtypes, libxnd, shared


def remove_outer_dimensions(t, n):
    """
    Remove `n` outer dimensions from type `t`.
    """
    return ndtypes.ndt(" * ".join(str(t).split(" * ")[n:]))


# TODO: Refactor this as a dispatcher subclass so it can easier access input type and can be jitted itself.
def register_kernel(signature):
    """
    Registers a gumath kernel based on the dispatcher. Takes in each of the inputs and then the result as arguments.

    Like:
        @register_kernel_direct("... * float64, ... * int64 -> int64")
        def something(a, b, res):
            for i in range(a.shape):
                a[i]
                ...

    This has to know the intputs/ouputs ndtypes at compile time, because the xnd wrapper Numba API relies on this.
    """

    def inner(fn):
        gufunc = None
        already_built = set()

        def wrap(*args):
            nonlocal gufunc
            arg_types = [a.type for a in args]
            apply_spec = ndtypes.ndt(signature).apply(arg_types)
            if not apply_spec:
                raise ValueError(
                    f"Failed to generate kernel for {fn}. Inputs of types {arg_types} do not match {signature}."
                )
            # Removes the outer dimensions from the input/output types to get the types that are passed in on the stack
            stack_types = tuple(
                remove_outer_dimensions(t, apply_spec.outer_dims)
                for t in apply_spec.in_types + apply_spec.out_types
            )
            if stack_types not in already_built:
                dispatcher = numba.njit(tuple(map(libxnd.XndWrapperType, stack_types)))(
                    fn
                )
                # there is some max name length in numba
                name = f"numba__{dispatcher}"[:20]

                gufunc = register_kernel_direct(name, signature)(
                    wrap_kernel_dispatcher(len(stack_types))(dispatcher)
                )
                already_built.add(stack_types)

            return gufunc(*args)

        return wrap

    return inner


def wrap_kernel_dispatcher(n_args):
    """
    Returns a new dispatcher that is suitable to be registered with `register_kernel_direct`.

    The original dispatcher must have wrapper types specified explicitly so the

    Use like:

        @register_kernel_direct("some name", "int64, 10 * int64 -> int64")
        @wrap_kernel_dispatcher(3)
        @njit(XndObjectWrapperType(ndt("int64"))(...))
        def something(a, b, ret):
            ret[()] = a + b[0]
    """

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
