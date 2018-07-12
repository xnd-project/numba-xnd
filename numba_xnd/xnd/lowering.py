from xnd import xnd
from numba.extending import typeof_impl, box, unbox, NativeValue, lower_builtin
from llvmlite import ir
from llvmlite.ir import PointerType as ptr

from ..libxnd import xnd_t, XndType
from . import api
from . import types
from ..shared import pycapsule_import


@typeof_impl.register(xnd)
def typeof_xnd(val, c):
    return types.py_xnd_type


@unbox(types.PyXndType)
def unbox_xnd(typ, obj, c):
    """
    Convert a xnd object to a native xnd_t ptr.
    """
    get_XndObject_xnd = c.builder.module.get_or_insert_function(
        ir.FunctionType(ptr(xnd_t), [c.pyapi.pyobj]), name="get_XndObject_xnd"
    )
    return NativeValue(c.builder.call(get_XndObject_xnd, [obj]))


@box(types.PyXndType)
def box_xnd(typ, val, c):
    """
    Convert a native ptr(xnd_t) structure to a xnd object.
    """
    xnd_from_xnd = pycapsule_import(
        c,
        "xnd._xnd._API",
        5,
        ir.FunctionType(c.pyapi.pyobj, [c.pyapi.pyobj, ptr(xnd_t)]),
        name="xnd_from_xnd",
    )

    xnd_type = c.pyapi.unserialize(c.pyapi.serialize_object(xnd))
    res = c.builder.call(xnd_from_xnd, [xnd_type, val])
    c.pyapi.decref(xnd_type)
    c.pyapi.incref(res)
    return res


# These functions are no-ops, but they exist so that at the Python API, the user has a way to
# convert from a higher level api to a lower level one, without mixing them together.


@lower_builtin(api.py_xnd_to_xnd, types.PyXndType)
def py_xnd_to_xnd_impl(context, builder, sig, args):
    return args[0]


@lower_builtin(api.xnd_to_py_xnd, XndType)
def xnd_to_py_xnd_impl(context, builder, sig, args):
    return args[0]
