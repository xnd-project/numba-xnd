import numba.extending
import numba.types

from . import structs
from .. import libndtypes, shared


xnd_subtree = shared.wrap_c_func(
    "xnd_subtree",
    structs.xnd_type,
    (
        structs.xnd_type,
        shared.integer_list_type,
        numba.types.int32,
        libndtypes.ndt_context_type,
    ),
)

xnd_multikey = shared.wrap_c_func(
    "xnd_multikey",
    structs.xnd_type,
    (
        structs.xnd_type,
        shared.integer_list_type,
        numba.types.int32,
        libndtypes.ndt_context_type,
    ),
)

xnd_equal = shared.wrap_c_func(
    "xnd_equal",
    numba.types.int32,
    (structs.xnd_type, structs.xnd_type, libndtypes.ndt_context_type),
)

xnd_strict_equal = shared.wrap_c_func(
    "xnd_strict_equal",
    numba.types.int32,
    (structs.xnd_type, structs.xnd_type, libndtypes.ndt_context_type),
)
