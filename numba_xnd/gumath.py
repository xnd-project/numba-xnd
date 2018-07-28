# import inspect

import gumath
import llvmlite.ir

import numba

from . import libndtypes, libxnd, shared


def register_gumath_kernel(name, signature):
    """
    Registers a Gumath kernel that calls the Numba dispatcher. Like:

        @register_gumath_kernel("some_name", "... * ... -> ...")
        @jit
        def something...
    """

    def inner(dispatcher):
        # number_args = len(inspect.signature(dispatcher.py_func).parameters)
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
