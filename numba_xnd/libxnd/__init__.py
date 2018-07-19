import xnd
import llvmlite

# expose
from .structs import *  # NOQA
from .functions import *  # NOQA

llvmlite.binding.load_library_permanently(xnd._xnd.__file__)
