import ndtypes

import numba

from .. import libndtypes


class XndSpec(numba.types.Type):
    """
    Similar to libndtypes.NdtSpec
    """

    def __init__(self, ndt_type, name):
        assert isinstance(ndt_type, ndtypes.ndt)
        self.ndt_type = ndt_type
        super().__init__(name=f"{name}({ndt_type})")


@numba.extending.overload_attribute(XndSpec, "ndim")
def xnd_wrapper_ndim(x):
    def get(x):
        return x.type.ndim

    return get


# @numba.extending.register_model(XndWrapperType)
# class XndWrapperModel(numba.extending.models.PrimitiveModel):
#     def __init__(self, dmm, fe_type):
#         super().__init__(dmm, fe_type, shared.ptr(structs.xnd_t))


# @shared.lower_and_type("getitem", XndWrapperType, numba.types.Integer)
# def xnd_wrapper_getitem(xnd_wrapper, i):
#     x = xnd_wrapper_to_xnd(xnd_wrapper)
#     # do subtree things
#     return xnd_to_xnd_wrapper(x)
