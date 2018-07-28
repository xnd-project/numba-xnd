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


@numba.extending.overload_attribute(XndSpec, "ndim")
def xnd_wrapper_ndim(x):
    def get(x):
        return x.type.ndim

    return get


def ndtypes_index(t):
    """
    Returns the resulting ndtype after indexing t by some int.
    """
    first, *rest = str(t).split(" * ")
    return ndtypes.ndt(" * ".join(rest))
