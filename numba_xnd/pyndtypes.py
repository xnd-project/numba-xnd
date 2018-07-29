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


# Copy some overloads from ndt wrapper
numba.extending.overload_attribute(NdtObjectWrapperType, "shape")(
    libndtypes.ndt_wrapper_shape
)
numba.extending.overload_attribute(NdtObjectWrapperType, "ndim")(
    libndtypes.ndt_wrapper_ndim
)
