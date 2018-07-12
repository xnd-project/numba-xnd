from numba.extending import type_callable, infer_getattr
from numba.typing.templates import AttributeTemplate

from numba import types as numba_types

from . import api
from . import types
from .. import libndtypes


@infer_getattr
class XndAttribute(AttributeTemplate):
    key = types.XndType

    def resolve_type(self, ary):
        return libndtypes.ndt_type
