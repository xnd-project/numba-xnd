import xnd

import numba.datamodel
import numba.extending

from .. import ndtypes, pyxnd, shared

XndObjectWrapperType = shared.create_numba_type(
    "XndObjectWrapper", shared.ptr(pyxnd.xnd_object)
)
xnd_object_wrapper_type = XndObjectWrapperType()


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return xnd_object_wrapper_type


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
    if xnd_object_wrapper_t != xnd_object_wrapper_type:
        return

    sig = pyxnd.xnd_object_type(xnd_object_wrapper_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic
def wrap_xnd_object(typingctx, xnd_object_t):
    if xnd_object_t != pyxnd.xnd_object_type:
        return

    sig = xnd_object_wrapper_type(pyxnd.xnd_object_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.overload_attribute(XndObjectWrapperType, "type")
def xnd_type_impl(_):
    def get(py_xnd):
        return ndtypes.wrap_ndt_object(unwrap_xnd_object(py_xnd).type)

    return get
