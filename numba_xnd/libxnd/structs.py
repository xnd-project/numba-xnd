from ..shared import create_opaque_struct, ptr
from .. import libndtypes

xnd_type, xnd_t, create_xnd = create_opaque_struct(
    "xnd_t", {"type": (libndtypes.ndt_type, ptr(libndtypes.ndt_t))}
)