import xnd

import numba.extending
import numba.types

from . import libxnd, shared

xnd_object = shared.WrappedCStruct(
    "XndObject", {"xnd": libxnd.xnd_t.numba_type}, embedded={"xnd"}
)


xnd_from_type_xnd = shared.WrappedCFunction(
    "xnd_from_type_xnd",
    xnd_object.numba_type,
    (shared.c_string_type, libxnd.xnd_t.numba_type),
)

xnd_from_xnd_view = shared.WrappedCFunction(
    "xnd_from_xnd_view", xnd_object.numba_type, (libxnd.xnd_view_t.numba_type,)
)


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return libxnd.xnd_view_t.WrapperNumbaType(val.type)


@numba.extending.unbox(libxnd.xnd_view_t.WrapperNumbaType)
def unbox_xnd_wrapper(typ, o, c):
    x_o = c.builder.bitcast(o, xnd_object.llvm_ptr_type)
    x = xnd_object.getattr_impl(None, c.builder, None, x_o, "xnd")
    x_v = libxnd.xnd_view_from_xnd.codegen(c.builder, (o, x))
    return numba.extending.NativeValue(x_v)


@numba.extending.box(libxnd.xnd_view_t.WrapperNumbaType)
def box_xnd_wrapper(typ, x, c):
    x_o = xnd_from_xnd_view.codegen(c.builder, (x,))
    o = c.builder.bitcast(x_o, shared.ptr(shared.char))
    c.pyapi.incref(o)
    return o
