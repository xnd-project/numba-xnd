from numba import types
from ndtypes import ndt
from numba.extending import (
    typeof_impl,
    register_model,
    box,
    unbox,
    NativeValue,
    overload_attribute,
    type_callable,
    lower_builtin,
)
from llvmlite import ir
from llvmlite.ir import PointerType as ptr

from ..utils import pycapsule_import
from .libndtypes import (
    NdtModel,
    ndt_t,
    ndt_as_ndarray,
    create_ndt_ndarray,
    create_ndt_context,
    ndt_type,
    NdtType,
)


class PyNdtType(types.Type):
    def __init__(self):
        super().__init__(name="PyNdt")


py_ndt_type = PyNdtType()


@typeof_impl.register(ndt)
def typeof_ndt(val, c):
    return py_ndt_type


register_model(PyNdtType)(NdtModel)


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


@type_callable(py_ndt_to_ndt)
def type_py_ndt_to_ndt(context):
    def typer(x):
        if isinstance(x, PyNdtType):
            return ndt_type

    return typer


@lower_builtin(py_ndt_to_ndt, PyNdtType)
def py_ndt_to_ndt_impl(context, builder, sig, args):
    return args[0]


def ndt_to_py_ndt(x):
    raise NotImplementedError()


@type_callable(py_ndt_to_ndt)
def type_ndt_to_py_ndt(context):
    def typer(x):
        if isinstance(x, NdtType):
            return py_ndt_type

    return typer


@lower_builtin(ndt_to_py_ndt, NdtType)
def ndt_to_py_ndt_impl(context, builder, sig, args):
    return args[0]


@overload_attribute(PyNdtType, "shape")
def py_ndt_shape(_):
    def get(py_ndt):
        a = create_ndt_ndarray()
        ctx = create_ndt_context()
        n = py_ndt_to_ndt(py_ndt)
        ndt_as_ndarray(a, n, ctx)
        return a.shape

    return get


@overload_attribute(PyNdtType, "ndim")
def py_ndt_ndim(_):
    def get(py_ndt):
        a = create_ndt_ndarray()
        ctx = create_ndt_context()
        n = py_ndt_to_ndt(py_ndt)
        ndt_as_ndarray(a, n, ctx)
        return a.ndim

    return get
