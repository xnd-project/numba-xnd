import ndtypes

import numba

from . import libndtypes, shared


class NdtObjectType(
    shared.CStructType,
    c_name="NdtObject",
    attrs={"ndt": libndtypes.NdtType(nrt_allocated=False)},
):
    pass


# ndt_from_type = shared.CFunctionIntrinsic(
#     "ndt_from_type", NdtObjectType(), (libndtypes.NdtType(),)
# )


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return libndtypes.NdtWrapperType(False, val)


@numba.extending.unbox(libndtypes.NdtWrapperType)
def unbox_ndt_wrapper(typ, o, c):
    n = NdtObjectType.getattr_impl(
        builder=c.builder, attr="ndt", struct=o, i=shared.index(0)
    )
    return numba.extending.NativeValue(n)


# Disable boxing for now since it isn't working right.
# @numba.extending.box(libndtypes.ndt_t.WrapperNumbaType)
# def box_ndt_wrapper(typ, n, c):
# numba.cgutils.printf(
#     c.builder,
#     "before tag = %d\n",
#     libndtypes.ndt_t.getattr_impl(None, c.builder, None, n, "tag"),
# )
# numba.cgutils.hexdump(c.builder, n, shared.i64(libndtypes.ndt_t.n_bytes))
# val = c.builder.load(n)
# new_n = c.builder.alloca(val.type)
# c.builder.store(val, new_n)
# numba.cgutils.hexdump(c.builder, new_n, shared.i64(libndtypes.ndt_t.n_bytes))

# numba.cgutils.printf(
#     c.builder,
#     "after tag = %d\n",
#     libndtypes.ndt_t.getattr_impl(None, c.builder, None, new_n, "tag"),
# )
# # new_n = numba.cgutils.alloca_once_value(c.builder, c.builder.load(n))
# n_o = ndt_from_type.codegen(c.builder, (n,))
# o = c.builder.bitcast(n_o, shared.ptr(shared.char))
# c.pyapi.incref(o)
# return o
