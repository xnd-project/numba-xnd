import llvmlite
import sys

# register types
from . import typing as _  # NOQA

# expose
from .lowering import *  # NOQA
from .models import *  # NOQA
from .types import *  # NOQA
from .llvm import *  # NOQA


if sys.platform.startswith("linux"):
    llvmlite.binding.load_library_permanently("libndtypes.so")
elif sys.platform.startswith("darwin"):
    llvmlite.binding.load_library_permanently("libndtypes.dylib")
elif sys.platform.startswith("win"):
    raise ImportWarning("Don't know how to load libndtypes library on windows")
