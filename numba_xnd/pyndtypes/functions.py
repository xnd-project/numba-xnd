from . import structs
from .. import libndtypes, shared

ndt_from_type = shared.wrap_c_func(
    "ndt_from_type", structs.ndt_object_type, (libndtypes.ndt_type,)
)
