import llvmlite
import ndtypes
import xnd

import numba
import numba.extending
import numba.types

from . import libndtypes, shared

llvmlite.binding.load_library_permanently(xnd._xnd.__file__)


xnd_type, xnd_t, create_xnd, XndWrapperType, wrap_xnd, unwrap_xnd = shared.create_opaque_struct(
    "xnd_t",
    {"type": libndtypes.ndt_type, "ptr": shared.c_string_type},
    create_wrapper=True,
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


@numba.extending.overload_attribute(XndWrapperType, "type")
def xnd_wrapper_type(x_wrapper_t):
    def get(x_wrapper):
        x = unwrap_xnd(x_wrapper)
        return libndtypes.wrap_ndt(x.type, x_wrapper)

    return get


@numba.extending.overload_attribute(XndWrapperType, "ndim")
def xnd_wrapper_ndim(x_wrapped):
    def get(x_wrapped):
        return x_wrapped.type.ndim

    return get


@numba.extending.overload_attribute(XndWrapperType, "shape")
def xnd_wrapper_shape(x_wrapped):
    def get(x_wrapped):
        return x_wrapped.type.shape

    return get


@numba.extending.overload_attribute(XndWrapperType, "value")
def xnd_wrapper_value(x_wrapper):
    n = x_wrapper.ndt_value

    if n == ndtypes.ndt("int64"):

        def get(x_wrapper):
            x = unwrap_xnd(x_wrapper)
            return shared.ptr_load_type(numba.types.int64, x.ptr)

        return get

    if n == ndtypes.ndt("float64"):

        def get(x_wrapper):
            x = unwrap_xnd(x_wrapper)
            return shared.ptr_load_type(numba.types.float64, x.ptr)

        return get


def ndtypes_index(t):
    """
    Returns the resulting ndtype after indexing t by some int.
    """
    first, *rest = str(t).split(" * ")
    return ndtypes.ndt(" * ".join(rest))


@shared.overload_any("getitem")
def xnd_wrapper_getitem(x_wrapper, index):
    if not isinstance(x_wrapper, XndWrapperType):
        return

    if isinstance(index, numba.types.Integer):
        resulting_type = str(ndtypes_index(x_wrapper.ndt_value))

        def getitem(x_wrapper, index):
            x = unwrap_xnd(x_wrapper)
            x_index = create_xnd_index()
            x_index.tag = XND_KEY_INDEX
            x_index.Index = index
            ret_xnd = create_xnd()
            ctx = libndtypes.ndt_static_context()
            xnd_subtree(ret_xnd, x, x_index, shared.i64_to_i32(1), ctx)
            assert not shared.ptr_is_none(ret_xnd.ptr)
            assert not libndtypes.ndt_err_occurred(ctx)
            return wrap_xnd(ret_xnd, resulting_type)

        return getitem
    elif isinstance(index, numba.types.BaseTuple):
        resulting_type = x_wrapper.ndt_value
        for i in index:
            if isinstance(i, numba.types.Integer):
                resulting_type = ndtypes_index(resulting_type)
            else:
                return
        resulting_type = str(resulting_type)
        n_items = len(index)
        if n_items == 0:
            return lambda x_wrapper, index: x_wrapper

        def getitem(x_wrapper, index):
            x = unwrap_xnd(x_wrapper)
            x_index = create_xnd_index(n_items)
            for i in range(n_items):
                x_index_cur = x_index[i]
                x_index_cur.tag = XND_KEY_INDEX
                x_index_cur.Index = index[i]
            ret_xnd = create_xnd()
            ctx = libndtypes.ndt_static_context()
            xnd_multikey(ret_xnd, x, x_index, shared.i64_to_i32(n_items), ctx)
            assert not shared.ptr_is_none(ret_xnd.ptr)
            assert not libndtypes.ndt_err_occurred(ctx)
            return wrap_xnd(ret_xnd, resulting_type)

        return getitem


@shared.overload_any("setitem")
def xnd_wrapper_setitem(x_wrapper, index, value):
    if not isinstance(x_wrapper, XndWrapperType):
        return
    if value == numba.types.int64:

        def setitem(x_wrapper, index, value):
            shared.ptr_store_type(
                numba.types.int64, unwrap_xnd(x_wrapper[index]).ptr, value
            )

        return setitem

    if value == numba.types.float64:

        def setitem(x_wrapper, index, value):
            shared.ptr_store_type(
                numba.types.float64, unwrap_xnd(x_wrapper[index]).ptr, value
            )

        return setitem
