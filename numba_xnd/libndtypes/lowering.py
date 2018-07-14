from llvmlite import ir

from numba.extending import lower_getattr, intrinsic
from numba.targets.listobj import ListInstance
from numba.targets.imputils import impl_ret_new_ref
from numba import cgutils
import numba.types

from ..shared import ptr, int_, index, i64
from . import types
from . import llvm


@intrinsic
def create_ndt_ndarray(typingctx):
    sig = types.ndt_ndarray_type()

    def codegen(context, builder, sig, args):
        return builder.alloca(llvm.ndt_ndarray_t)

    return sig, codegen


@intrinsic
def create_ndt_context(typingctx):
    sig = types.ndt_context_type()

    def codegen(context, builder, sig, args):
        return builder.alloca(llvm.ndt_context_t)

    return sig, codegen


@intrinsic
def ndt_as_ndarray(typingctx, a, t, ctx):
    if not (
        isinstance(a, types.NdtNdarrayType)
        and isinstance(t, types.NdtType)
        and isinstance(ctx, types.NdtContextType)
    ):
        return

    sig = numba.types.int32(
        types.ndt_ndarray_type, types.ndt_type, types.ndt_context_type
    )

    def codegen(context, builder, sig, args):
        ndt_as_ndarray_ = builder.module.get_or_insert_function(
            ir.FunctionType(
                int_,
                [ptr(llvm.ndt_ndarray_t), ptr(llvm.ndt_t), ptr(llvm.ndt_context_t)],
            ),
            name="ndt_as_ndarray",
        )
        return builder.call(ndt_as_ndarray_, args)

    return sig, codegen


@lower_getattr(types.NdtType, "ndim")
def ndt_ndim_impl(context, builder, typ, value):
    get_ndt_t_ndim = builder.module.get_or_insert_function(
        ir.FunctionType(ptr(int_), [ptr(llvm.ndt_t)]), name="get_ndt_t_ndim"
    )
    return builder.load(builder.call(get_ndt_t_ndim, [value]))


@lower_getattr(types.NdtNdarrayType, "ndim")
def ndt_ndarray_ndim_impl(context, builder, typ, value):
    print(builder.module)
    get_ndt_ndarray_t_ndim = builder.module.get_or_insert_function(
        ir.FunctionType(ptr(int_), [ptr(llvm.ndt_ndarray_t)]),
        name="get_ndt_ndarray_t_ndim",
    )
    return builder.load(builder.call(get_ndt_ndarray_t_ndim, [value]))


@lower_getattr(types.NdtNdarrayType, "shape")
def ndt_ndarray_shape_impl(context, builder, typ, value):
    get_ndt_ndarray_t_shape = builder.module.get_or_insert_function(
        ir.FunctionType(ptr(llvm.ndt_ndarray_t_shape), [ptr(llvm.ndt_ndarray_t)]),
        name="get_ndt_ndarray_t_shape",
    )

    array = builder.call(get_ndt_ndarray_t_shape, [value])
    ndim = builder.sext(ndt_ndarray_ndim_impl(context, builder, None, value), i64)
    inst = ListInstance.allocate(context, builder, types.shape_type, ndim)
    inst.size = ndim
    with cgutils.for_range(builder, ndim) as loop:
        i = loop.index
        inst.setitem(
            idx=i,
            val=builder.load(builder.gep(array, [index(0), i])),
            incref=True,  # no idea what incref does
        )

    return impl_ret_new_ref(context, builder, types.shape_type, inst.value)
