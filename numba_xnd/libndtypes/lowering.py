from llvmlite import ir

from numba.extending import lower_builtin, lower_getattr
from numba.targets.listobj import ListInstance
from numba.targets.imputils import impl_ret_new_ref
from numba import cgutils

from ..shared import ptr, int_, index, i64, sizes
from . import api
from . import types
from . import llvm


@lower_builtin(api.create_ndt_ndarray)
def create_ndt_ndarray_impl(context, builder, sig, args):
    return builder.alloca(llvm.ndt_ndarray_t)


@lower_builtin(api.create_ndt_context)
def create_ndt_context_impl(context, builder, sig, args):
    return builder.alloca(llvm.ndt_context_t)


@lower_builtin(
    api.ndt_as_ndarray, types.NdtNdarrayType, types.NdtType, types.NdtContextType
)
def ndt_as_ndarray_impl(context, builder, sig, args):
    ndt_as_ndarray_ = builder.module.get_or_insert_function(
        ir.FunctionType(
            int_, [ptr(llvm.ndt_ndarray_t), ptr(llvm.ndt_t), ptr(llvm.ndt_context_t)]
        ),
        name="ndt_as_ndarray",
    )
    return builder.call(ndt_as_ndarray_, args)


@lower_getattr(types.NdtType, "ndim")
def ndt_ndarray_ndim_impl(context, builder, typ, value):
    return builder.load(
        builder.bitcast(
            builder.gep(value, [index(0), index(sizes.OFFSETOF_NDT_T_NDIM)]), ptr(int_)
        )
    )


@lower_getattr(types.NdtNdarrayType, "ndim")
def ndt_ndarray_ndim_impl(context, builder, typ, value):
    return builder.load(
        builder.bitcast(
            builder.gep(value, [index(0), index(sizes.OFFSETOF_NDT_ARRAY_T_NDIM)]),
            ptr(int_),
        )
    )


@lower_getattr(types.NdtNdarrayType, "shape")
def ndt_ndarray_shape_impl(context, builder, typ, value):
    array = builder.bitcast(
        builder.gep(value, [index(0), index(sizes.OFFSETOF_NDT_ARRAY_T_SHAPE)]),
        ptr(ir.ArrayType(i64, sizes.CONST_NDT_MAX_DIM)),
    )

    # now we have to convert the LLVM array to a Numba list instance
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
