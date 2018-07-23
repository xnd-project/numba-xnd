from .. import libxnd, pyndtypes, shared

memory_block_object_type, memory_block_object, create_memory_block_object = shared.create_opaque_struct(
    "MemoryBlockObject",
    {"type": pyndtypes.ndt_object_type, "xnd": libxnd.xnd_master_type},
)


xnd_object_type, xnd_object, create_xnd_object = shared.create_opaque_struct(
    "XndObject",
    {
        "mblock": memory_block_object_type,
        "type": pyndtypes.ndt_object_type,
        "xnd": libxnd.xnd_type,
    },
    embedded={"xnd"},
)
