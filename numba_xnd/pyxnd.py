import xnd

import numba.extending
import numba.types

from . import libndtypes, libxnd, pyndtypes, shared

memory_block_object_type, memory_block_object, create_memory_block_object = shared.create_opaque_struct(
    "MemoryBlockObject",
    {"type": pyndtypes.ndt_object_type, "xnd": libxnd.xnd_master_type},
)


xnd_object_type, xnd_object, create_xnd_object, XndObjectWrapperType, wrap_xnd_object, unwrap_xnd_object = shared.create_opaque_struct(
    "XndObject",
    {
        "mblock": memory_block_object_type,
        "type": pyndtypes.ndt_object_type,
        "xnd": libxnd.xnd_type,
    },
    embedded={"xnd"},
    wrapper_spec_class=libxnd.XndSpec,
)


@numba.extending.box(type(xnd_object_type))
def box_xnd(typ, val, c):
    """
    Convert a native ptr(xnd_t) structure to a xnd object.
    """
    obj = c.builder.bitcast(val, c.pyapi.pyobj)
    c.pyapi.incref(obj)
    return obj


xnd_from_type_xnd = shared.wrap_c_func(
    "xnd_from_type_xnd", xnd_object_type, (numba.types.pyobject, libxnd.xnd_type)
)

xnd_view_move_ndt = shared.wrap_c_func(
    "xnd_view_move_ndt", xnd_object_type, (xnd_object_type, libndtypes.ndt_type)
)


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return XndObjectWrapperType(val.type)


@numba.extending.overload_attribute(XndObjectWrapperType, "type")
def xnd_wrapper_type(x):
    type_ = str(x.ndt_type)

    def get(x):
        x_ = unwrap_xnd_object(x)
        return pyndtypes.wrap_ndt_object(x_.type, type_)

    return get


@numba.extending.unbox(XndObjectWrapperType)
def unbox_xnd(typ, obj, c):
    return numba.extending.NativeValue(c.builder.bitcast(obj, shared.ptr(xnd_object)))


# TODO: Boxing/unboxing should maybe be defined on XndObjectType instead, because you don'y
# need the ndt type to do this. However, then we would have to always convert to those when returning
# or would need to setup automatic conversions. Another option might be to have XndObjectWrapperType subclass
# XndObjectType, but then I would worry that maybe the attributes would carry over, which we don't want.
# Explicit conversions here present less confusion.
@numba.extending.box(XndObjectWrapperType)
def box_xnd(typ, val, c):
    """
    Convert a native ptr(xnd_t) structure to a xnd object.
    """
    obj = c.builder.bitcast(val, c.pyapi.pyobj)
    c.pyapi.incref(obj)
    return obj
