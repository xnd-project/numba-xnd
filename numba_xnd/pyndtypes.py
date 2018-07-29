import ndtypes

import numba.datamodel
import numba.extending

from . import libndtypes, shared

ndt_object_type, ndt_object, create_ndt_object, NdtObjectWrapperType, wrap_ndt_object, unwrap_ndt_object = shared.create_opaque_struct(
    "NdtObject", {"ndt": libndtypes.ndt_type}, wrapper_spec_class=libndtypes.NdtSpec
)


ndt_from_type = shared.wrap_c_func(
    "ndt_from_type", ndt_object_type, (libndtypes.ndt_type,)
)


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return NdtObjectWrapperType(val)


@numba.extending.unbox(NdtObjectWrapperType)
def unbox_ndt(typ, obj, c):
    return numba.extending.NativeValue(c.builder.bitcast(obj, shared.ptr(ndt_object)))


@numba.extending.box(NdtObjectWrapperType)
def box_ndt(typ, val, c):
    """
    Convert a native ptr(ndt_t) structure to a ndt object.
    """
    obj = c.builder.bitcast(val, c.pyapi.pyobj)
    c.pyapi.incref(obj)
    return obj
