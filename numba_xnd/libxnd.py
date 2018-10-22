import llvmlite
import ndtypes
import numba
import numba.extending
import numba.types
import xnd

from . import libndtypes, shared

llvmlite.binding.load_library_permanently(xnd._xnd.__file__)


class XndType(
    shared.CStructType,
    c_name="xnd_t",
    attrs={"type": libndtypes.NdtType(False), "ptr": shared.c_string_type},
):
    pass


class XndViewType(
    shared.CStructType,
    c_name="xnd_view_t",
    attrs={
        "flags": numba.types.uint32,
        "obj": shared.c_string_type,
        "view": XndType(False),
    },
    embedded={"view"},
):
    pass


alloc_xnd_view = XndViewType.alloc


class XndViewWrapperType(shared.WrapperType, inner_type=XndViewType):
    pass


wrap_xnd_view, unwrap_xnd_view = XndViewWrapperType.wrap, XndViewWrapperType.unwrap


# xnd_key enums for tag property
XND_KEY_INDEX = 0
XND_KEY_FIELD_NAME = 1
XND_KEY_SLICE = 2


class XndIndexType(
    shared.CStructType,
    c_name="xnd_index_t",
    attrs={
        "tag": numba.types.int32,
        "Index": numba.types.int64,
        "FieldName": shared.c_string_type,
        "Slice": libndtypes.NdtSliceType(False),
    },
    embedded={"Slice"},
):
    pass


alloc_xnd_index = XndIndexType.alloc

xnd_view_from_xnd = shared.CFunctionIntrinsic(
    "xnd_view_from_xnd", numba.types.void, (XndViewType, shared.c_string_type, XndType)
)


xnd_view_subscript = shared.CFunctionIntrinsic(
    "xnd_view_subscript",
    numba.types.void,
    (
        XndViewType,
        XndViewType,
        XndIndexType,
        numba.types.intc,
        libndtypes.NdtContextType,
    ),
)
xnd_equal = shared.CFunctionIntrinsic(
    "xnd_equal", numba.types.intc, (XndType, XndType, libndtypes.NdtContextType)
)

xnd_strict_equal = shared.CFunctionIntrinsic(
    "xnd_strict_equal", numba.types.intc, (XndType, XndType, libndtypes.NdtContextType)
)


@numba.extending.overload_attribute(XndViewWrapperType, "type")
def xnd_view_wrapper__type(x_type):
    n_str = str(x_type.ndt_value)
    return lambda x: libndtypes.wrap_ndt(unwrap_xnd_view(x).view(0).type(0), n_str)


@numba.extending.overload_attribute(XndViewWrapperType, "ndim")
def xnd_view_wrapper__ndim(x_type):
    return lambda x: x.type.ndim


@numba.extending.overload_attribute(XndViewWrapperType, "value")
def xnd_view_wraper__value(x_type):
    n = x_type.ndt_value

    if n == ndtypes.ndt("int64"):
        primitive_type = numba.types.int64
    elif n == ndtypes.ndt("float64"):
        primitive_type = numba.types.float64
    else:
        return
    load_type = shared.create_ptr_load_type(primitive_type)
    return lambda x: load_type(unwrap_xnd_view(x).view(0).ptr(0))


def ndtypes_index(t):
    """
    Returns the resulting ndtype after indexing t by some int.
    """
    first, *rest = str(t).split(" * ")
    return ndtypes.ndt(" * ".join(rest))


@shared.overload_any("getitem")
def xnd_view_wraper__getitem(x, index):
    if not isinstance(x, XndViewWrapperType):
        return

    if isinstance(index, numba.types.Integer):
        resulting_type = str(ndtypes_index(x.ndt_value))

        def getitem(x, index):
            x_index = alloc_xnd_index(1)
            x_index.tag(0, XND_KEY_INDEX)
            x_index.Index(0, index)
            ctx = libndtypes.ndt_static_context()
            ret_x = alloc_xnd_view(1)
            xnd_view_subscript(
                ret_x, unwrap_xnd_view(x), x_index, shared.i64_to_i32(1), ctx
            )
            print("done")
            libndtypes.check_error(ctx, ret_x.view(0).ptr(0))
            print("checked")
            print(ret_x.flags(0))
            print(shared.ptr_is_none(ret_x.obj(0)))
            return wrap_xnd_view(ret_x, resulting_type)

        return getitem
    if isinstance(index, numba.types.BaseTuple):
        resulting_type = x.ndt_value
        for i in index:
            if isinstance(i, numba.types.Integer):
                resulting_type = ndtypes_index(resulting_type)
            else:
                return
        resulting_type = str(resulting_type)
        n_items = len(index)
        if n_items == 0:
            return lambda x, index: x

        def getitem(x, index):
            x_index = alloc_xnd_index(n_items)
            for i in range(n_items):
                x_index.tag(i, shared.i64_to_i32(XND_KEY_INDEX))
                x_index.Index(i, index[i])
            ctx = libndtypes.ndt_static_context()
            ret_x = alloc_xnd_view(1)
            print(x_index.tag(0))
            print(x_index.tag(1))
            xnd_view_subscript(
                ret_x, unwrap_xnd_view(x), x_index, shared.i64_to_i32(n_items), ctx
            )
            print(x_index.tag(0))
            print(x_index.tag(1))
            libndtypes.check_error(ctx, ret_x.view(0).ptr(0))
            return wrap_xnd_view(ret_x, resulting_type)

        return getitem


@shared.overload_any("setitem")
def xnd_wrapper_setitem(x_type, index_type, value_type):
    if not isinstance(x_type, XndViewWrapperType):
        return
    if value_type in (numba.types.int64, numba.types.float64):
        ptr_store_type = shared.create_ptr_store_type(value_type)
        return lambda x, index, value: ptr_store_type(
            unwrap_xnd_view(x[index]).view.ptr, value
        )
