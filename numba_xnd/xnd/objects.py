import xnd

import numba.datamodel
import numba.extending

from .. import libndtypes, libxnd, ndtypes, pyxnd, shared


class XndObjectWrapperType(libxnd.XndSpec):
    def __init__(self, ndt_type):
        super().__init__(ndt_type, name="XndObjectWrapper")


@numba.extending.register_model(XndObjectWrapperType)
class XndObjectWrapperModel(numba.extending.models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        super().__init__(dmm, fe_type, shared.ptr(pyxnd.xnd_object))


@numba.extending.overload_attribute(XndObjectWrapperType, "type")
def xnd_wrapper_type(x):
    type_ = str(x.ndt_type)

    def get(x):
        x_ = unwrap_xnd_object(x)
        return ndtypes.wrap_ndt_object(x_.type, type_)

    return get


# @numba.extending.infer_getattr
# class XndObjectWrapperTemplate(numba.typing.templates.AttributeTemplate):
#     key = XndObjectWrapperType

#     def resolve_type(self, xnd_spec_t):
#         return ndtypes.NdtObjectWrapperType(xnd_spec_t.ndt_type)


# @numba.extending.lower_getattr(XndObjectWrapperType, "type")
# def _inner_getattr_impl(context, builder, typ, value, attr):
#     is_embedded = attr in embedded
#     ret = _get_attr(builder, value, attr, is_embedded)
#     return ret if is_embedded else builder.load(ret)


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return XndObjectWrapperType(val.type)


@numba.extending.unbox(XndObjectWrapperType)
def unbox_xnd(typ, obj, c):
    return numba.extending.NativeValue(
        c.builder.bitcast(obj, shared.ptr(pyxnd.xnd_object))
    )


# TODO: Boxing/unboxing should maybe be defined on XndObjectType instead, because you don'y
# need the ndt type to do this. However, then we would have to always convert to those when returning
# or would need to setup automatic conversions. Another option might be to have XndObjectWrapperType subclass
# XndObjectType, but then I would worry that maybe the attributes would carry over, which we don't want.
# Explicit conversions here present less confusion.
@numba.extending.box(XndObjectWrapperType)
def box_xnd(typ, val, c):
    """
    Convert a native ptr(xnd_t) structure to a xnd object.
    """
    obj = c.builder.bitcast(val, c.pyapi.pyobj)
    c.pyapi.incref(obj)
    return obj


@numba.extending.intrinsic
def unwrap_xnd_object(typingctx, xnd_object_wrapper_t):
    if not isinstance(xnd_object_wrapper_t, XndObjectWrapperType):
        return

    sig = pyxnd.xnd_object_type(xnd_object_wrapper_t)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic(support_literals=True)
def wrap_xnd_object(typingctx, xnd_object_t, ndt_spec_t):
    if xnd_object_t != pyxnd.xnd_object_type or not isinstance(
        ndt_spec_t, libndtypes.NdtSpec
    ):
        return

    sig = XndObjectWrapperType(ndt_spec_t.ndt_type)(xnd_object_t, ndt_spec_t)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen
