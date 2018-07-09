from numba.extending import register_model
from ..libndtypes import NdtModel

from .types import PyNdtType

register_model(PyNdtType)(NdtModel)
