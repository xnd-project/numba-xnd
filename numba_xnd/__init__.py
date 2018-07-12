import xnd_structinfo
import llvmlite

# register libraries
from . import libndtypes as _  # NOQA
from . import ndtypes as _  # NOQA

llvmlite.binding.load_library_permanently(xnd_structinfo.__file__)
