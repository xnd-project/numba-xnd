import llvmlite
import llvmlite.ir
import ndtypes

import numba
import numba.extending
import numba.targets.imputils
import numba.targets.listobj
import numba.types

from . import shared

llvmlite.binding.load_library_permanently(ndtypes._ndtypes.__file__)


NDT_MAX_DIM = 128


ndt_t = shared.WrappedCStruct("ndt_t", {"ndim": numba.types.int32}, create_wrapper=True)
wrap_ndt, unwrap_ndt = ndt_t.wrap, ndt_t.unwrap


ndt_ndarray_t = shared.WrappedCStruct(
    "ndt_ndarray_t",
    {
        "ndim": numba.types.int32,
        "shape": numba.types.UniTuple(numba.types.int64, NDT_MAX_DIM),
    },
)
create_ndt_ndarray = ndt_ndarray_t.create
ndt_slice_t = shared.WrappedCStruct(
    "ndt_slice_t",
    {"start": numba.types.int64, "stop": numba.types.int64, "step": numba.types.int64},
)
ndt_context_t = shared.WrappedCStruct(
    "ndt_context_t",
    {
        "flags": numba.types.uint32,
        "err": numba.types.int32,
        "msg": numba.types.int32,
        "ConstMsg": shared.c_string_type,
        "DynamicMsg": shared.c_string_type,
    },
)
create_ndt_context = ndt_context_t.create

# for gumath kernel
@numba.extending.unbox(ndt_context_t.NumbaType)
def unbox_ndt_context(typ, val, c):
    return numba.extending.NativeValue(
        c.builder.bitcast(val, ndt_context_t.llvm_ptr_type)
    )


ndt_as_ndarray = shared.WrappedCFunction(
    "ndt_as_ndarray",
    numba.types.int32,
    (ndt_ndarray_t.numba_type, ndt_t.numba_type, ndt_context_t.numba_type),
)

ndt_is_concrete = shared.WrappedCFunction(
    "ndt_is_concrete", numba.types.int32, (ndt_t.numba_type,)
)

ndt_err_occurred = shared.WrappedCFunction(
    "ndt_err_occurred", numba.types.boolean, (ndt_context_t.numba_type,)
)

ndt_context_msg = shared.WrappedCFunction(
    "ndt_context_msg", shared.c_string_type, (ndt_context_t.numba_type,)
)


@numba.njit
def ndt_static_context():
    ctx = create_ndt_context()
    ctx.flags = 0
    ctx.err = 0
    ctx.msg = 0
    ctx.ConstMsg = shared.c_string_const("Success")
    return ctx


@numba.extending.overload_attribute(ndt_t.WrapperNumbaType, "shape")
def ndt_wrapper_shape(t):
    ndim = shared.get_ndim(t.ndt_value)

    def get(t):
        a = create_ndt_ndarray()
        ctx = ndt_static_context()
        ndt_as_ndarray(a, unwrap_ndt(t), ctx)
        if ndt_err_occurred(ctx):
            shared.print_c_string(ndt_context_msg(ctx))
            raise RuntimeError("ndt_as_ndarray failed.")
        return a.shape[:ndim]

    return get


@numba.extending.overload_attribute(ndt_t.WrapperNumbaType, "ndim")
def ndt_wrapper_ndim(t):
    ndim = shared.get_ndim(t.ndt_value)

    def get(t):
        return ndim

    return get
