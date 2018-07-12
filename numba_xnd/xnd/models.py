from numba.extending import register_model
from ..libxnd import XndModel

from .types import PyXndType

register_model(PyXndType)(XndModel)
