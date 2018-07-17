import llvmlite.ir
import numba.types
from ..shared import create_opaque_struct, int_, i64, create_numba_type, ptr

# CONST_NDT_MAX_DIM = 128

ndt_ndarray_t_shape = ptr(i64)
shape_type = create_numba_type("NdtNdarrayShape", ndt_ndarray_t_shape)

ndt_type, ndt_t, create_ndt = create_opaque_struct(
    "ndt_t", {"ndim": (numba.types.int32, int_)}
)

ndt_ndarray_type, ndt_ndarray_t, create_ndt_ndarray = create_opaque_struct(
    "ndt_ndarray_t",
    {"ndim": (numba.types.int32, int_), "shape": (shape_type, ndt_ndarray_t_shape)},
)
ndt_slice_type, ndt_slice_t, create_ndt_slice = create_opaque_struct("ndt_slice_t", {})
ndt_context_type, ndt_context_t, create_ndt_context = create_opaque_struct(
    "ndt_context_t", {}
)
