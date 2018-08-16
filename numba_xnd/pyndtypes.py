import ndtypes

import numba

from . import libndtypes, shared

ndt_object = shared.WrappedCStruct("NdtObject", {"ndt": libndtypes.ndt_t.numba_type})


ndt_from_type = shared.WrappedCFunction(
    "ndt_from_type", ndt_object.numba_type, (libndtypes.ndt_t.numba_type,)
)


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return libndtypes.ndt_t.WrapperNumbaType(val)


@numba.extending.unbox(libndtypes.ndt_t.WrapperNumbaType)
def unbox_ndt_wrapper(typ, o, c):
    n_o = c.builder.bitcast(o, ndt_object.llvm_ptr_type)
    n = ndt_object.getattr_impl(None, c.builder, None, n_o, "ndt")
    return numba.extending.NativeValue(n)


@numba.extending.box(libndtypes.ndt_t.WrapperNumbaType)
def box_ndt_wrapper(typ, n, c):
    # val = c.builder.load(n)
    # new_n = c.builder.alloca(val.type)
    # c.builder.store(val, new_n)
    # new_n = numba.cgutils.alloca_once_value(c.builder, c.builder.load(n))
    n_o = ndt_from_type.codegen(c.builder, (n,))
    o = c.builder.bitcast(n_o, shared.ptr(shared.char))
    c.pyapi.incref(o)
    return o
