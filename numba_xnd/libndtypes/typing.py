from numba.extending import type_callable, infer_getattr
from numba.typing.templates import AttributeTemplate

from numba import types as numba_types

from . import api
from . import types


@type_callable(api.create_ndt_ndarray)
def type_create_ndt_ndarray(context):
    def typer():
        return types.ndt_ndarray_type

    return typer


@type_callable(api.create_ndt_context)
def type_create_ndt_context(context):
    def typer():
        return types.ndt_context_type

    return typer


@type_callable(api.ndt_as_ndarray)
def type_ndt_as_ndarray(context):
    def typer(nd, t, ctx):
        if (
            isinstance(nd, types.NdtNdarrayType)
            and isinstance(t, types.NdtType)
            and isinstance(ctx, types.NdtContextType)
        ):
            return numba_types.int32

    return typer


@infer_getattr
class NdtAttribute(AttributeTemplate):
    key = types.NdtType

    def resolve_ndim(self, ary):
        return numba_types.int32


@infer_getattr
class NdtNdarrayAttribute(AttributeTemplate):
    key = types.NdtNdarrayType

    def resolve_ndim(self, ary):
        return numba_types.int32

    def resolve_shape(self, ary):
        return types.shape_type
