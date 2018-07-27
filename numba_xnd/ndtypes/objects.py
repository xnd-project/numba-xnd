import ndtypes

import numba.datamodel
import numba.extending

from .. import libndtypes, pyndtypes, shared


class NdtObjectWrapperType(libndtypes.NdtSpec):
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


# @numba.extending.intrinsic
# def wrap_ndt_object(typingctx, ndt_object_t, ndt_type_t):
#     if ndt_object_t != pyndtypes.ndt_object_type or not isinstance(
#         ndt_type_t, libndtypes.NdtSpec
#     ):
#         return

#     sig = NdtObjectWrapperType(ndt_type_t.ndt)(ndt_object_t, ndt_type_t)

#     def codegen(context, builder, sig, args):
#         return args[0]

#     return sig, codegen
