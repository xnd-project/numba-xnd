import numba.extending
import numba.types

from . import structs
from .. import libndtypes, shared

# Apply zero or more indices to the input *x* and return a typed view. Valid
# indices are integers or strings for record fields.

# This function is more general than pure array indexing, hence the name. For
# example, it is possible to index into nested records that in turn contain
# arrays.
xnd_subtree = shared.wrap_c_func(
    "xnd_subtree",
    numba.types.void,
    (
        structs.xnd_type,
        structs.xnd_type,  # this is the return value, but is passed in at LLVM level
        structs.xnd_index_type,
        numba.types.intc,
        libndtypes.ndt_context_type,
    ),
)

# Apply zero or more keys to the input *x* and return a typed view. Valid
# keys are integers or slices.

# This function differs from `xnd_subtree` in that it allows
# mixed indexing and slicing for fixed dimensions.  Records and tuples
# cannot be sliced.

# Variable dimensions can be sliced, but do not support mixed indexing
# and slicing.
xnd_multikey = shared.wrap_c_func(
    "xnd_multikey",
    numba.types.void,
    (
        structs.xnd_type,  # this is the return value, but is passed in at LLVM level
        structs.xnd_type,
        structs.xnd_index_type,
        numba.types.intc,
        libndtypes.ndt_context_type,
    ),
)

xnd_equal = shared.wrap_c_func(
    "xnd_equal",
    numba.types.intc,
    (structs.xnd_type, structs.xnd_type, libndtypes.ndt_context_type),
)

xnd_strict_equal = shared.wrap_c_func(
    "xnd_strict_equal",
    numba.types.intc,
    (structs.xnd_type, structs.xnd_type, libndtypes.ndt_context_type),
)
