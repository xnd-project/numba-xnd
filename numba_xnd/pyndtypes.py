import ndtypes

import numba.datamodel
import numba.extending

from . import libndtypes, shared

ndt_object_type, ndt_object, create_ndt_object, NdtObjectWrapperType, wrap_ndt_object, unwrap_ndt_object = shared.create_opaque_struct(
    "NdtObject",
    {"ndt": libndtypes.ndt_type},
    create_wrapper=True,
    is_python_object=True,
)


ndt_from_type = shared.wrap_c_func(
    "ndt_from_type", ndt_object_type, (libndtypes.ndt_type,)
)


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return NdtObjectWrapperType(val)


@numba.njit
def to_wrapped_ndt(ndt_object_wrapped):
    ndt_object = unwrap_ndt_object(ndt_object_wrapped)
    return libndtypes.wrap_ndt(ndt_object.ndt, ndt_object_wrapped)


@numba.extending.overload_attribute(NdtObjectWrapperType, "shape")
def ndt_wrapper_shape(t):
    def get(t):
        return to_wrapped_ndt(t).shape

    return get


@numba.extending.overload_attribute(NdtObjectWrapperType, "ndim")
def ndt_wrapper_ndim(t):
    def get(t):
        return to_wrapped_ndt(t).ndim

    return get
