from llvmlite.ir import PointerType as ptr

from numba.extending import models, register_model

from . import types
from . import llvm


@register_model(types.NdtType)
class NdtModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(llvm.ndt_t)
        super().__init__(dmm, fe_type, be_type)


@register_model(types.NdtNdarrayType)
class NdtNdarrayModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(llvm.ndt_ndarray_t)
        super().__init__(dmm, fe_type, be_type)


@register_model(types.NdtContextType)
class NdtContextModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(llvm.ndt_context_t)
        super().__init__(dmm, fe_type, be_type)
