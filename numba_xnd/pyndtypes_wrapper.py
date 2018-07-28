import ndtypes

import numba.datamodel
import numba.extending

from . import libndtypes, libndtypes_wrapper, pyndtypes, shared


class NdtObjectWrapperType(libndtypes_wrapper.NdtSpec):
    def __init__(self, ndt):
        super().__init__(ndt, "NdtObjectWrapper")


@numba.extending.register_model(NdtObjectWrapperType)
class NdtObjectWrapperModel(numba.extending.models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        super().__init__(dmm, fe_type, shared.ptr(pyndtypes.ndt_object))


@numba.extending.typeof_impl.register(ndtypes.ndt)
def typeof_ndt(val, c):
    return NdtObjectWrapperType(val)


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
    if not isinstance(ndt_object_wrapper_t, NdtObjectWrapperType):
        return

    sig = pyndtypes.ndt_object_type(ndt_object_wrapper_t)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen


@numba.extending.intrinsic(support_literals=True)
def wrap_ndt_object(typingctx, ndt_object_t, ndt_type_t):
    """
    Takes in a ndt object and associates an ndtypes.ndt with it. The second argument can either be a string
    of the ndt or some NdtSpec subtype.
    """
    if ndt_object_t != pyndtypes.ndt_object_type:
        return
    if isinstance(ndt_type_t, numba.types.Const):
        n = ndtypes.ndt(ndt_type_t.value)
        arg_type = numba.types.string
    elif isinstance(ndt_type_t, libndtypes_wrapper.NdtSpec):
        n = ndt_type_t.ndt_type
        arg_type = ndt_type_t
    else:
        return

    sig = NdtObjectWrapperType(n)(ndt_object_t, arg_type)

    def codegen(context, builder, sig, args):
        return args[0]

    return sig, codegen
