import llvmlite

import xnd_structinfo

from . import libndtypes as _  # NOQA
from . import libxnd as _  # NOQA
from . import ndtypes as _  # NOQA
from . import pyndtypes as _  # NOQA
from . import pyxnd as _  # NOQA
from . import xnd as _  # NOQA
from .gumath import register_gumath_kernel  # NOQA

llvmlite.binding.load_library_permanently(xnd_structinfo.__file__)
