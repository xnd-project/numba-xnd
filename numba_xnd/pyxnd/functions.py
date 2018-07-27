import numba.extending
import numba.types

from . import structs
from .. import libndtypes, libxnd, shared

xnd_from_type_xnd = shared.wrap_c_func(
    "xnd_from_type_xnd",
    structs.xnd_object_type,
    (numba.types.pyobject, libxnd.xnd_type),
)

xnd_view_move_ndt = shared.wrap_c_func(
    "xnd_view_move_ndt",
    structs.xnd_object_type,
    (structs.xnd_object_type, libndtypes.ndt_type),
)
