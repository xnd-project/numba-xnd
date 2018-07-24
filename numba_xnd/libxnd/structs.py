import numba.extending
import numba.types

from .. import libndtypes, shared

xnd_type, xnd_t, create_xnd = shared.create_opaque_struct(
    "xnd_t", {"type": libndtypes.ndt_type, "ptr": shared.c_string_type}
)


# xnd_key enums for tag property
XND_KEY_INDEX = 0
XND_KEY_FIELD_NAME = 1
XND_KEY_SLICE = 2

xnd_index_type, xnd_index_t, create_xnd_index = shared.create_opaque_struct(
    "xnd_index_t",
    {
        "tag": numba.types.int64,
        "Index": numba.types.int64,
        "FieldName": shared.c_string_type,
        "Slice": libndtypes.ndt_slice_type,
    },
    embedded={"Slice"},
)

xnd_master_type, xnd_master_t, create_xnd_master = shared.create_opaque_struct(
    "xnd_master_t",
    {"flags": numba.types.int32, "master": xnd_type},
    embedded={"master"},
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
