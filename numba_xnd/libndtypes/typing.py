from numba.extending import type_callable, infer_getattr
from numba.typing.templates import AttributeTemplate

import numba.types

from . import types


@infer_getattr
class NdtAttribute(AttributeTemplate):
    key = types.NdtType

    def resolve_ndim(self, ary):
        return numba.types.int32


@infer_getattr
class NdtNdarrayAttribute(AttributeTemplate):
    key = types.NdtNdarrayType

    def resolve_ndim(self, ary):
        return numba.types.int32

    def resolve_shape(self, ary):
        return types.shape_type
