import llvmlite
import ndtypes

from .functions import *  # NOQA
from .objects import *  # NOQA
from .structs import *  # NOQA

llvmlite.binding.load_library_permanently(ndtypes._ndtypes.__file__)
