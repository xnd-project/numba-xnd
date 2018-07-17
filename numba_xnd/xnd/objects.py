import xnd
import llvmlite.ir
import numba.datamodel
import numba.extending
from ..shared import create_numba_type, ptr
from .. import libxnd
from .. import ndtypes


PyXndType = create_numba_type("PyNdt", ptr(libxnd.xnd_t))
py_xnd_type = PyXndType()


@numba.extending.typeof_impl.register(xnd.xnd)
def typeof_xnd(val, c):
    return py_xnd_type


@numba.extending.unbox(PyXndType)
def unbox_ndt(typ, obj, c):
    """
    Convert a xnd object to a native xnd_t ptr.
    """
    get_XndObject_xnd = c.builder.module.get_or_insert_function(
        llvmlite.ir.FunctionType(ptr(libxnd.xnd_t), [c.pyapi.pyobj]),
        name="get_XndObject_xnd",
    )
    return numba.extending.NativeValue(c.builder.call(get_XndObject_xnd, [obj]))


@numba.extending.box(PyXndType)
def box_ndt(typ, val, c):
    """
    Convert a native ptr(xnd_t) structure to a xnd object.
    """
    xnd_from_type_xnd = c.builder.module.get_or_insert_function(
        llvmlite.ir.FunctionType(c.pyapi.pyobj, [c.pyapi.pyobj, ptr(libxnd.xnd_t)]),
        name="xnd_from_type_xnd",
    )
    xnd_type = c.pyapi.unserialize(c.pyapi.serialize_object(xnd.xnd))
    res = c.builder.call(xnd_from_type_xnd, [xnd_type, val])
    c.pyapi.decref(xnd_type)
    c.pyapi.incref(res)
    return res


@numba.extending.intrinsic
def py_xnd_to_xnd(typingctx, py_xnd_t):
    if py_xnd_t != py_xnd_type:
        return

    sig = libxnd.xnd_type(py_xnd_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic
def xnd_to_py_xnd(typingctx, xnd_t_):
    if xnd_t_ != libxnd.xnd_type:
        return

    sig = py_xnd_type(libxnd.xnd_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.overload_attribute(PyXndType, "type")
def py_xnd_type_(_):
    def get(py_xnd):
        x = py_xnd_to_xnd(py_xnd)
        return ndtypes.ndt_to_py_ndt(x.type)

    return get
