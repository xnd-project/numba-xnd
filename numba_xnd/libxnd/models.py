from llvmlite.ir import PointerType as ptr

from numba.extending import models, register_model

from . import types
from . import llvm


@register_model(types.XndType)
class XndModel(models.PrimitiveModel):
    def __init__(self, dmm, fe_type):
        be_type = ptr(llvm.xnd_t)
        super().__init__(dmm, fe_type, be_type)
