from xnd import xnd
from numba.extending import typeof_impl, overload_attribute, type_callable

from ..ndtypes import ndt_to_py_ndt
from .. import libxnd
from . import types
from . import api


@typeof_impl.register(xnd)
def typeof_xnd(val, c):
    return types.py_xnd_type


@type_callable(api.py_xnd_to_xnd)
def type_py_xnd_to_xnd(context):
    def typer(x):
        if isinstance(x, types.PyXndType):
            return libxnd.xnd_type

    return typer


@type_callable(api.py_xnd_to_xnd)
def type_xnd_to_py_xnd(context):
    def typer(x):
        if isinstance(x, libxnd.XndType):
            return types.py_xnd_type

    return typer


@overload_attribute(types.PyXndType, "type")
def py_xnd_shape(_):
    def get(py_xnd):
        x = api.py_xnd_to_xnd(py_xnd)
        return ndt_to_py_ndt(x.type)

    return get
