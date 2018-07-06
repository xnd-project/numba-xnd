from numba import types
from ndtypes import ndt
from numba.extending import (
    typeof_impl,
    register_model,
    box,
    unbox,
    NativeValue,
    overload_attribute,
)
from llvmlite import ir
from llvmlite.ir import PointerType as ptr

from ..utils import pycapsule_import
from .libndtypes import (
    NdtModel,
    ndt_t,
    ndt_as_ndarray,
    create_ndt_array,
    create_ndt_context,
)


class PyNdtType(types.Type):
    def __init__(self):
        super().__init__(name="PyNdt")


py_ndt_type = PyNdtType()


@typeof_impl.register(ndt)
def typeof_ndt(val, c):
    return py_ndt_type


register_model(py_ndt_type)(NdtModel)


@unbox(PyNdtType)
def unbox_ndt(typ, obj, c):
    """
    Convert a ndt object to a native ndt_t ptr.
    """
    const_ndt = pycapsule_import(
        c,
        "ndtypes._ndtypes._API",
        2,
        ir.FunctionType(ptr(ndt_t), [c.pyapi.pyobj]),
        name="const_ndt",
    )

    return NativeValue(c.builder.call(const_ndt, [obj]))


@box(PyNdtType)
def box_ndt(typ, val, c):
    """
    Convert a native ptr(ndt_t) structure to a ndt object.
    """
    ndt_from_type = pycapsule_import(
        c,
        "ndtypes._ndtypes._API",
        6,
        ir.FunctionType(c.pyapi.pyobj, [ptr(ndt_t)]),
        name="ndt_from_type",
    )

    res = c.builder.call(ndt_from_type, [val])
    c.pyapi.incref(res)
    return res


def py_ndt_to_ndt(x):
    raise NotImplementedError()


def ndt_to_py_ndt(x):
    raise NotImplementedError()


@overload_attribute(PyNdtType, "shape")
def py_ndt_shape(_):
    def get(n):
        a = create_ndt_array()
        ctx = create_ndt_context()
        ndt_as_ndarray(a, n, ctx)
        return a.shape

    return get
