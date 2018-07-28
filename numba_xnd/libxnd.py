import llvmlite
import xnd

import numba.extending
import numba.types

from . import libndtypes, shared

llvmlite.binding.load_library_permanently(xnd._xnd.__file__)


xnd_type, xnd_t, create_xnd = shared.create_opaque_struct(
    "xnd_t", {"type": libndtypes.ndt_type, "ptr": shared.c_string_type}
)


# xnd_key enums for tag property
XND_KEY_INDEX = 0
XND_KEY_FIELD_NAME = 1
XND_KEY_SLICE = 2

xnd_index_type, xnd_index_t, create_xnd_index = shared.create_opaque_struct(
    "xnd_index_t",
    {
        "tag": numba.types.int64,
        "Index": numba.types.int64,
        "FieldName": shared.c_string_type,
        "Slice": libndtypes.ndt_slice_type,
    },
    embedded={"Slice"},
)

xnd_master_type, xnd_master_t, create_xnd_master = shared.create_opaque_struct(
    "xnd_master_t",
    {"flags": numba.types.int32, "master": xnd_type},
    embedded={"master"},
)


# Apply zero or more indices to the input *x* and return a typed view. Valid
# indices are integers or strings for record fields.

# This function is more general than pure array indexing, hence the name. For
# example, it is possible to index into nested records that in turn contain
# arrays.
xnd_subtree = shared.wrap_c_func(
    "xnd_subtree",
    numba.types.void,
    (
        xnd_type,
        xnd_type,  # this is the return value, but is passed in at LLVM level
        xnd_index_type,
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
        xnd_type,  # this is the return value, but is passed in at LLVM level
        xnd_type,
        xnd_index_type,
        numba.types.intc,
        libndtypes.ndt_context_type,
    ),
)

xnd_equal = shared.wrap_c_func(
    "xnd_equal", numba.types.intc, (xnd_type, xnd_type, libndtypes.ndt_context_type)
)

xnd_strict_equal = shared.wrap_c_func(
    "xnd_strict_equal",
    numba.types.intc,
    (xnd_type, xnd_type, libndtypes.ndt_context_type),
)