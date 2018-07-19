import numba.types
from .. import shared


ndt_type, ndt_t, create_ndt = shared.create_opaque_struct(
    "ndt_t", {"ndim": numba.types.int32}
)

ndt_ndarray_type, ndt_ndarray_t, create_ndt_ndarray = shared.create_opaque_struct(
    "ndt_ndarray_t", {"ndim": numba.types.int32, "shape": shared.integer_list_type}
)
ndt_slice_type, ndt_slice_t, create_ndt_slice = shared.create_opaque_struct(
    "ndt_slice_t",
    {"start": numba.types.int64, "stop": numba.types.int64, "step": numba.types.int64},
)
ndt_context_type, ndt_context_t, create_ndt_context = shared.create_opaque_struct(
    "ndt_context_t", {}
)
