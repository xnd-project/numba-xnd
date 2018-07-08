import sys

from llvmlite import ir
from llvmlite.ir import PointerType as ptr
import llvmlite

from numba.extending import (
    models,
    register_model,
    lower_builtin,
    lower_getattr,
    type_callable,
    infer_getattr,
)
from numba.typing.templates import AttributeTemplate
from numba.targets.listobj import ListInstance
from numba.targets.imputils import impl_ret_new_ref
from numba import types, cgutils

from ..utils import int_, char, index, i64
from .. import sizes

if sys.platform.startswith("linux"):
    llvmlite.binding.load_library_permanently("libndtypes.so")
elif sys.platform.startswith("darwin"):
    llvmlite.binding.load_library_permanently("libndtypes.dylib")
elif sys.platform.startswith("win"):
    raise ImportWarning("Don't know how to load libndtypes library on windows")


ndt_t = ir.ArrayType(char, sizes.SIZEOF_NDT_T)
ndt_context_t = ir.ArrayType(char, sizes.SIZEOF_NDT_CONTEXT_T)
ndt_ndarray_t = ir.ArrayType(char, sizes.SIZEOF_NDT_NDARRAY_T)


class NdtType(types.Type):
    def __init__(self):
        super().__init__(name="Ndt")


ndt_type = NdtType()


class NdtNdarrayType(types.Type):
    def __init__(self):
        super().__init__(name="NdtNdarray")


ndt_ndarray_type = NdtNdarrayType()


class NdtContextType(types.Type):
    def __init__(self):
        super().__init__(name="NdtContext")


ndt_context_type = NdtContextType()


@register_model(NdtType)
class NdtModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(ndt_t)
        super().__init__(dmm, fe_type, be_type)


@register_model(NdtNdarrayType)
class NdtNdarrayModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(ndt_ndarray_t)
        super().__init__(dmm, fe_type, be_type)


@register_model(NdtContextType)
class NdtContextModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(ndt_context_t)
        super().__init__(dmm, fe_type, be_type)


def ndt_as_ndarray(a, n, ctx):
    raise NotImplementedError()


def create_ndt_ndarray():
    raise NotImplementedError()


def create_ndt_context():
    raise NotImplementedError()


@type_callable(create_ndt_ndarray)
def type_create_ndt_ndarray(context):
    def typer():
        return ndt_ndarray_type

    return typer


@type_callable(create_ndt_context)
def type_create_ndt_context(context):
    def typer():
        return ndt_context_type

    return typer


@lower_builtin(create_ndt_ndarray)
def create_ndt_ndarray_impl(context, builder, sig, args):
    return builder.alloca(ndt_ndarray_t)


@lower_builtin(create_ndt_context)
def create_ndt_context_impl(context, builder, sig, args):
    return builder.alloca(ndt_context_t)


@type_callable(ndt_as_ndarray)
def type_ndt_as_ndarray(context):
    def typer(nd, t, ctx):
        if (
            isinstance(nd, NdtNdarrayType)
            and isinstance(t, NdtType)
            and isinstance(ctx, NdtContextType)
        ):
            return types.int32

    return typer


@lower_builtin(ndt_as_ndarray, NdtNdarrayType, NdtType, NdtContextType)
def ndt_as_ndarray_impl(context, builder, sig, args):
    ndt_as_ndarray_ = builder.module.get_or_insert_function(
        ir.FunctionType(int_, [ptr(ndt_ndarray_t), ptr(ndt_t), ptr(ndt_context_t)]),
        name="ndt_as_ndarray",
    )
    return builder.call(ndt_as_ndarray_, args)


@infer_getattr
class NdtNdarrayAttribute(AttributeTemplate):
    key = NdtNdarrayType

    def resolve_ndim(self, ary):
        return types.int32

    def resolve_shape(self, ary):
        return types.List(types.int64)


@lower_getattr(NdtNdarrayType, "ndim")
def ndt_ndarray_ndim_impl(context, builder, typ, value):
    return builder.load(
        builder.bitcast(
            builder.gep(value, [index(0), index(sizes.OFFSETOF_NDT_ARRAY_T_NDIM)]),
            ptr(int_),
        )
    )


@lower_getattr(NdtNdarrayType, "shape")
def ndt_ndarray_shape_impl(context, builder, typ, value):
    array = builder.bitcast(
        builder.gep(value, [index(0), index(sizes.OFFSETOF_NDT_ARRAY_T_SHAPE)]),
        ptr(ir.ArrayType(i64, sizes.CONST_NDT_MAX_DIM)),
    )

    # now we have to convert the LLVM array to a Numba list instance

    ndim = builder.sext(ndt_ndarray_ndim_impl(context, builder, None, value), i64)
    list_type = types.List(types.int64)
    inst = ListInstance.allocate(context, builder, list_type, ndim)
    inst.size = ndim
    with cgutils.for_range(builder, ndim) as loop:
        i = loop.index
        inst.setitem(
            idx=i,
            val=builder.load(builder.gep(array, [index(0), i])),
            incref=True,  # no idea what incref does
        )

    return impl_ret_new_ref(context, builder, list_type, inst.value)
