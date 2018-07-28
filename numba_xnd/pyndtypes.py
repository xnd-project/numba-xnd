from . import libndtypes, shared

ndt_object_type, ndt_object, create_ndt_object = shared.create_opaque_struct(
    "NdtObject", {"ndt": libndtypes.ndt_type}
)


ndt_from_type = shared.wrap_c_func(
    "ndt_from_type", ndt_object_type, (libndtypes.ndt_type,)
)
