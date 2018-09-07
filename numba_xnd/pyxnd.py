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
    return libxnd.xnd_view_mem_info_wrapper.WrapperNumbaType(val.type)


@numba.extending.unbox(libxnd.xnd_view_mem_info_wrapper.WrapperNumbaType)
def unbox_xnd_wrapper(typ, o, c):
    c.pyapi.incref(o)
    x_v_m_i = libxnd.create_xnd_view_mem_info_codegen(c.context, c.builder, None, None)
    x_v = libxnd.xnd_view_mem_info_get_data_impl(c.context, c.builder, None, x_v_m_i)

    x = xnd_object.getattr_impl(None, c.builder, None, o, "xnd")
    libxnd.xnd_view_from_xnd.codegen(c.builder, (x_v, o, x))
    c.context.nrt.incref(c.builder, typ, x_v_m_i)
    return numba.extending.NativeValue(x_v_m_i)


@numba.extending.box(libxnd.xnd_view_mem_info_wrapper.WrapperNumbaType)
def box_xnd_wrapper(typ, x_v_m_i, c):
    builder = c.builder
    x_v = libxnd.xnd_view_mem_info_get_data_impl(c.context, builder, None, x_v_m_i)

    # This means the view is from `xnd_view_from_xnd` and we have access to
    # the python object. We can just return the existing python object
    # TOOD: This could get moved to `xnd` to handle this set of flags
    flags = libxnd.xnd_view_t.getattr_impl(None, builder, None, x_v, "flags")
    flags_is_0 = builder.icmp_unsigned("==", flags, flags.type(0))

    o = libxnd.xnd_view_t.getattr_impl(None, builder, None, x_v, "obj")
    o_is_not_null = builder.icmp_unsigned("!=", o, o.type(None))

    has_original_object = builder.and_(flags_is_0, o_is_not_null)

    o_ptr = builder.alloca(o.type)
    with builder.if_else(has_original_object) as (then, otherwise):
        with then:
            builder.store(o, o_ptr)
        with otherwise:
            x_o = xnd_from_xnd_view.codegen(builder, (x_v,))
            o = builder.bitcast(x_o, shared.ptr(shared.char))
            builder.store(o, o_ptr)
    o = builder.load(o_ptr)
    c.pyapi.incref(o)
    return o
