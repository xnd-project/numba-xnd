import numba.extending
import numba.types
import xnd

from . import libxnd, shared


class XndObjectType(
    shared.CStructType,
    c_name="XndObject",
    attrs={"xnd": libxnd.XndType(False)},
    embedded={"xnd"},
):
    pass


xnd_from_xnd_view = shared.CFunctionIntrinsic(
    "xnd_from_xnd_view", XndObjectType(False), (libxnd.XndViewType,)
)


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return libxnd.XndViewWrapperType(True, val.type)


@numba.extending.unbox(libxnd.XndViewWrapperType)
def xnd_view_wraper__unbox(typ, o, c):
    """
    Create an xnd_view from the xnd on the object
    """
    # TODO: Do we need this?
    c.pyapi.incref(o)
    # create xnd_view
    xnd_view = libxnd.XndViewType._alloc_codegen(c.context, c.builder, shared.i64(1))

    # get xnd
    x = XndObjectType.getattr_impl(c.builder, "xnd", o, shared.index(0))

    # fill xnd view from xnd
    libxnd.xnd_view_from_xnd.codegen(c.builder, (xnd_view, o, x))

    # TODO: Do we need this?
    c.context.nrt.incref(c.builder, typ, xnd_view)

    return numba.extending.NativeValue(xnd_view)


@numba.extending.box(libxnd.XndViewWrapperType)
def xnd_view_wraper__box(typ, xnd_view, c):
    builder = c.builder

    flags = libxnd.XndViewType.getattr_impl(
        c.builder, "flags", xnd_view, shared.index(0)
    )
    flags_is_0 = builder.icmp_unsigned("==", flags, flags.type(0))

    o = libxnd.XndViewType.getattr_impl(c.builder, "obj", xnd_view, shared.index(0))
    o_is_not_null = builder.icmp_unsigned("!=", o, o.type(None))

    # This means the view is from `xnd_view_from_xnd` and we have access to
    # the python object. We can just return the existing python object
    # TOOD: Move this logic to `xnd` to handle this set of flags
    has_original_object = builder.and_(flags_is_0, o_is_not_null)

    o_ptr = builder.alloca(o.type)
    with builder.if_else(has_original_object) as (then, otherwise):
        with then:
            builder.store(o, o_ptr)
        with otherwise:
            builder.store(xnd_from_xnd_view.codegen(builder, (xnd_view,)), o_ptr)
    o = builder.load(o_ptr)

    # TODO: Do we need this?
    # c.pyapi.incref(o)
    return builder.load(o_ptr)
