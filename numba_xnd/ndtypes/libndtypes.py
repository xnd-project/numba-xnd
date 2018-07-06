from llvmlite import ir
from llvmlite.ir import PointerType as ptr, global_context as context

from numba.extending import models, register_model, lower_builtin
from numba import types

from ..utils import int_


ndt_t = context.get_identified_type("_ndt")
ndt_context_t = context.get_identified_type("_ndt_context")
ndt_ndarray_t = context.get_identified_type("ndt_ndarray_t")


class NdtType(types.Type):
    def __init__(self):
        super().__init__(name="Ndt")


class NdtNdarrayType(types.Type):
    def __init__(self):
        super().__init__(name="NdtNdarray")


class NdtContextType(types.Type):
    def __init__(self):
        super().__init__(name="NdtContext")


ndt_type = NdtType()


@register_model(ndt_type)
class NdtModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(ndt_t)
        super().__init__(dmm, fe_type, be_type)


def ndt_as_ndarray(a, n, ctx):
    raise NotImplementedError()


@lower_builtin(ndt_as_ndarray, NdtNdarrayType, NdtType, NdtContextType)
def ndt_as_ndarray_impl(context, builder, sig, args):
    xnd_ndim = builder.module.get_or_insert_function(
        ir.FunctionType(int_, [ptr(ndt_ndarray_t), ptr(ndt_t), ptr(ndt_context_t)]),
        name="ndt_as_ndarray",
    )
    return builder.call(xnd_ndim, [a.value for a in args])
