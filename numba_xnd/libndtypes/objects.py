import ndtypes

import numba


class NdtSpec(numba.types.Type):
    """
    We create a base class for things that should act like the `ndtypes.ndt` Python object.

    This is like the DTypeSpec in Numba.
    """

    def __init__(self, ndt, name):
        assert isinstance(ndt, ndtypes.ndt)
        self.ndt_type = ndt
        super().__init__(f"{name}({ndt})")


# TODO: get all properties of ndt and auto generate these, maybe using inspect
@numba.extending.overload_attribute(NdtSpec, "shape")
def ndt_wrapper_shape(t):
    shape = t.ndt_type.shape

    def get(t):
        return shape

    return get


@numba.extending.overload_attribute(NdtSpec, "ndim")
def ndt_wrapper_ndim(t):
    ndim = t.ndt_type.ndim

    def get(t):
        return ndim

    return get
