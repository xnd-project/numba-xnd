import ndtypes

import numba.datamodel
import numba.extending

from .. import pyndtypes, shared

NdtObjectWrapperType = shared.create_numba_type(
    "NdtObjectWrapper", shared.ptr(pyndtypes.ndt_object)
)
ndt_object_wrapper_type = NdtObjectWrapperType()


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return ndt_object_wrapper_type


@numba.extending.unbox(NdtObjectWrapperType)
def unbox_ndt(typ, obj, c):
    return numba.extending.NativeValue(
        c.builder.bitcast(obj, shared.ptr(pyndtypes.ndt_object))
    )


@numba.extending.box(NdtObjectWrapperType)
def box_ndt(typ, val, c):
    """
    Convert a native ptr(ndt_t) structure to a ndt object.
    """
    obj = c.builder.bitcast(val, c.pyapi.pyobj)
    c.pyapi.incref(obj)
    return obj


@numba.extending.intrinsic
def unwrap_ndt_object(typingctx, ndt_object_wrapper_t):
    if ndt_object_wrapper_t != ndt_object_wrapper_type:
        return

    sig = pyndtypes.ndt_object_type(ndt_object_wrapper_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic
def wrap_ndt_object(typingctx, ndt_object_t):
    if ndt_object_t != pyndtypes.ndt_object_type:
        return

    sig = ndt_object_wrapper_type(pyndtypes.ndt_object_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.overload_attribute(NdtObjectWrapperType, "shape")
def ndt_shape_impl(_):
    def get(py_ndt):
        n = unwrap_ndt_object(py_ndt)
        a = libndtypes.create_ndt_ndarray()
        ctx = libndtypes.create_ndt_context()
        libndtypes.ndt_as_ndarray(a, n.ndt, ctx)
        return libndtypes.ndt_dim_array_to_python_list(a.shape, n.ndim)

    return get


@numba.extending.overload_attribute(NdtObjectWrapperType, "ndim")
def ndt_ndim_impl(_):
    def get(py_ndt):
        return unwrap_ndt_object(py_ndt).ndt.ndim

    return get
