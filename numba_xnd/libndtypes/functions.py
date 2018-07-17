import numba.extending
import numba.types

from . import structs
from ..shared import wrap_c_func

ndt_as_ndarray = wrap_c_func(
    "ndt_as_ndarray",
    numba.types.int32,
    (structs.ndt_ndarray_type, structs.ndt_type, structs.ndt_context_type),
)
