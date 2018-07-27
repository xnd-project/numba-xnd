import ndtypes

import numba


class XndSpec(numba.types.Type):
    """
    Similar to libndtypes.NdtSpec
    """

    def __init__(self, ndt_type, name):
        assert isinstance(ndt_type, ndtypes.ndt)
        self.ndt_type = ndt_type
        super().__init__(name=f"{name}({ndt_type})")


@numba.extending.overload_attribute(XndSpec, "type")
def xnd_wrapper_type(t):
    type_ = t.ndt_type

    def get(t):
        # TODO: This gets lowered as an NdtWrapperObject, but it could be some other kind of thing that supports the NdtSpec
        # Maybe like an OpaqueType that has no runtime representation. To do this, we coul change the type registered with `ndtypes.ndt` to be this type
        return type_

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
