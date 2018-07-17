import ndtypes
import llvmlite.ir
import numba.datamodel
import numba.extending
from ..shared import create_numba_type, ptr, integer_list_to_python_list
from .. import libndtypes


PyNdtType = create_numba_type("PyNdt", ptr(libndtypes.ndt_t))
py_ndt_type = PyNdtType()


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return py_ndt_type


@numba.extending.unbox(PyNdtType)
def unbox_ndt(typ, obj, c):
    """
    Convert a ndt object to a native ndt_t ptr.
    """
    get_NdtObject_ndt = c.builder.module.get_or_insert_function(
        llvmlite.ir.FunctionType(ptr(libndtypes.ndt_t), [c.pyapi.pyobj]),
        name="get_NdtObject_ndt",
    )
    return numba.extending.NativeValue(c.builder.call(get_NdtObject_ndt, [obj]))


@numba.extending.box(PyNdtType)
def box_ndt(typ, val, c):
    """
    Convert a native ptr(ndt_t) structure to a ndt object.
    """
    ndt_from_type = c.builder.module.get_or_insert_function(
        llvmlite.ir.FunctionType(c.pyapi.pyobj, [ptr(libndtypes.ndt_t)]),
        name="ndt_from_type",
    )
    res = c.builder.call(ndt_from_type, [val])
    c.pyapi.incref(res)
    return res


@numba.extending.intrinsic
def py_ndt_to_ndt(typingctx, py_ndt_t):
    if py_ndt_t != py_ndt_type:
        return

    sig = libndtypes.ndt_type(py_ndt_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic
def ndt_to_py_ndt(typingctx, ndt_t_):
    if ndt_t_ != libndtypes.ndt_type:
        return

    sig = py_ndt_type(libndtypes.ndt_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.overload_attribute(PyNdtType, "shape")
def py_ndt_shape(_):
    def get(py_ndt):
        n = py_ndt_to_ndt(py_ndt)
        a = libndtypes.create_ndt_ndarray()
        ctx = libndtypes.create_ndt_context()
        libndtypes.ndt_as_ndarray(a, n, ctx)
        return integer_list_to_python_list(a.shape, a.ndim)

    return get


@numba.extending.overload_attribute(PyNdtType, "ndim")
def py_ndt_ndim(_):
    def get(py_ndt):
        return py_ndt_to_ndt(py_ndt).ndim

    return get
