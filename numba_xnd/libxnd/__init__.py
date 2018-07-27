import llvmlite
import xnd

from .functions import *  # NOQA
from .objects import *  # NOQA
from .structs import *  # NOQA

llvmlite.binding.load_library_permanently(xnd._xnd.__file__)
