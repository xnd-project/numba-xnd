import llvmlite.ir

import numba.types

from .. import shared

NDT_MAX_DIM = 128

ndt_dim_array = llvmlite.ir.ArrayType(shared.i64, NDT_MAX_DIM)
ndt_dim_array_type = shared.create_numba_type("NdtDimArray", ndt_dim_array)()

ndt_type, ndt_t, create_ndt = shared.create_opaque_struct(
    "ndt_t", {"ndim": numba.types.int32}
)

ndt_ndarray_type, ndt_ndarray_t, create_ndt_ndarray = shared.create_opaque_struct(
    "ndt_ndarray_t", {"ndim": numba.types.int32, "shape": ndt_dim_array_type}
)
ndt_slice_type, ndt_slice_t, create_ndt_slice = shared.create_opaque_struct(
    "ndt_slice_t",
    {"start": numba.types.int64, "stop": numba.types.int64, "step": numba.types.int64},
)
ndt_context_type, ndt_context_t, create_ndt_context = shared.create_opaque_struct(
    "ndt_context_t", {}
)
