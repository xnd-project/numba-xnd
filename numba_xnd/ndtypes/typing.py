from ndtypes import ndt
from numba.extending import typeof_impl, overload_attribute, type_callable

from .. import libndtypes
from . import types
from . import api


@typeof_impl.register(ndt)
def typeof_ndt(val, c):
    return types.py_ndt_type


@type_callable(api.py_ndt_to_ndt)
def type_py_ndt_to_ndt(context):
    def typer(x):
        if isinstance(x, types.PyNdtType):
            return libndtypes.ndt_type

    return typer


@type_callable(api.py_ndt_to_ndt)
def type_ndt_to_py_ndt(context):
    def typer(x):
        if isinstance(x, libndtypes.NdtType):
            return types.py_ndt_type

    return typer


@overload_attribute(types.PyNdtType, "shape")
def py_ndt_shape(_):
    def get(py_ndt):
        n = api.py_ndt_to_ndt(py_ndt)
        a = libndtypes.create_ndt_ndarray()
        ctx = libndtypes.create_ndt_context()
        libndtypes.ndt_as_ndarray(a, n, ctx)
        return a.shape

    return get


@overload_attribute(types.PyNdtType, "ndim")
def py_ndt_ndim(_):
    def get(py_ndt):
        return api.py_ndt_to_ndt(py_ndt).ndim

    return get
