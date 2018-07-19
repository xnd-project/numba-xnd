import numba.types
import numba.extending

from .. import shared
from .. import libndtypes

xnd_type, xnd_t, create_xnd = shared.create_opaque_struct(
    "xnd_t", {"type": libndtypes.ndt_type}
)

c_string = shared.ptr(shared.char)
c_string_type = shared.create_numba_type("CString", c_string)()


# xnd_key enums for tag property
XND_KEY_INDEX = 0
XND_KEY_FIELD_NAME = 1
XND_KEY_SLICE = 2

xnd_index_type, xnd_index_t, create_xnd_index = shared.create_opaque_struct(
    "xnd_index_t",
    {
        "tag": numba.types.int32,
        "Index": numba.types.int64,
        "FieldName": c_string_type,
        "Slice": libndtypes.ndt_slice_type,
    },
)


@numba.extending.intrinsic
def get_xnd_index(typing_ctx, x_t, i_t):
    if x_t != xnd_index_type or not isinstance(i_t, numba.types.Integer):
        return
    sig = xnd_index_type(xnd_index_type, numba.types.int64)

    def codegen(context, builder, sig, args):
        x, i = args
        return builder.gep(x, [i])

    return sig, codegen

