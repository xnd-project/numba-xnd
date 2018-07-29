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
    create_wrapper=True,
    is_python_object=True,
)


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
def xnd_object_wrapper_type(x):
    def get(x):
        x_ = unwrap_xnd_object(x)
        return pyndtypes.wrap_ndt_object(x_.type, x)

    return get


numba.extending.overload_attribute(XndObjectWrapperType, "ndim")(
    libxnd.xnd_wrapper_ndim
)


@numba.njit
def to_wrapped_xnd(x_object_wrapped):
    x_object = unwrap_xnd_object(x_object_wrapped)
    x = x_object.xnd
    return libxnd.wrap_xnd(x, x_object_wrapped)


@numba.extending.overload_attribute(XndObjectWrapperType, "value")
def xnd_object_wrapper_value(x_object_wrapped):
    def get(x_object_wrapped):
        return to_wrapped_xnd(x_object_wrapped).value

    return get
