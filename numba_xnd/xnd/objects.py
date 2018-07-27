import xnd

import numba.datamodel
import numba.extending

from .. import libxnd, ndtypes, pyxnd, shared


class XndObjectWrapperType(libxnd.XndSpec):
    def __init__(self, ndt_type):
        super().__init__(ndt_type, name="XndObjectWrapper")


@numba.extending.register_model(XndObjectWrapperType)
class XndObjectWrapperModel(numba.extending.models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        super().__init__(dmm, fe_type, shared.ptr(pyxnd.xnd_object))


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return XndObjectWrapperType(val.type)


@numba.extending.unbox(XndObjectWrapperType)
def unbox_xnd(typ, obj, c):
    return numba.extending.NativeValue(
        c.builder.bitcast(obj, shared.ptr(pyxnd.xnd_object))
    )


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


# @numba.extending.intrinsic
# def wrap_xnd_object(typingctx, xnd_object_t, type_t):
#     if xnd_object_t != pyxnd.xnd_object_type, :
#         return

#     sig = xnd_object_wrapper_type(pyxnd.xnd_object_type)

#     def codegen(context, builder, sig, args):
#         return args[0]

#     return sig, codegen
