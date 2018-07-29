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


ndt_dim_array = llvmlite.ir.ArrayType(shared.i64, NDT_MAX_DIM)
ndt_dim_array_type = shared.create_numba_type("NdtDimArray", ndt_dim_array)


ndt_type, ndt_t, create_ndt, NdtWrapperType, wrap_ndt, unwrap_ndt = shared.create_opaque_struct(
    "ndt_t", {"ndim": numba.types.int32}, create_wrapper=True
)

ndt_ndarray_type, ndt_ndarray_t, create_ndt_ndarray = shared.create_opaque_struct(
    "ndt_ndarray_t", {"ndim": numba.types.int32, "shape": ndt_dim_array_type}
)
ndt_slice_type, ndt_slice_t, create_ndt_slice = shared.create_opaque_struct(
    "ndt_slice_t",
    {"start": numba.types.int64, "stop": numba.types.int64, "step": numba.types.int64},
)
ndt_context_type, ndt_context_t, create_ndt_context = shared.create_opaque_struct(
    "ndt_context_t",
    {
        "flags": numba.types.uint32,
        "err": numba.types.int32,
        "msg": numba.types.int32,
        "ConstMsg": shared.c_string_type,
        "DynamicMsg": shared.c_string_type,
    },
)


ndt_as_ndarray = shared.wrap_c_func(
    "ndt_as_ndarray", numba.types.int32, (ndt_ndarray_type, ndt_type, ndt_context_type)
)

ndt_is_concrete = shared.wrap_c_func("ndt_is_concrete", numba.types.int32, (ndt_type,))

ndt_err_occurred = shared.wrap_c_func(
    "ndt_err_occurred", numba.types.boolean, (ndt_context_type,)
)

ndt_context_msg = shared.wrap_c_func(
    "ndt_context_msg", shared.c_string_type, (ndt_context_type,)
)


@numba.njit
def ndt_static_context():
    ctx = create_ndt_context()
    ctx.flags = 0
    ctx.err = 0
    ctx.msg = 0
    ctx.ConstMsg = shared.c_string_const("Success")
    return ctx


# TODO: look into geting all properties of ndt and auto generate these, maybe using inspect
@numba.extending.overload_attribute(NdtWrapperType, "shape")
def ndt_wrapper_shape(t):
    shape = t.ndt_value.shape

    def get(t):
        return shape

    return get


@numba.extending.overload_attribute(NdtWrapperType, "ndim")
def ndt_wrapper_ndim(t):
    ndim = t.ndt_value.ndim

    def get(t):
        return ndim

    return get
