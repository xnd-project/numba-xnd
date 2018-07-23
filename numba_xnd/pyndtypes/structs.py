from .. import libndtypes, shared

ndt_object_type, ndt_object, create_ndt_object = shared.create_opaque_struct(
    "NdtObject", {"ndt": libndtypes.ndt_type}
)
