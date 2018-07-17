import sys
import llvmlite

# expose
from .structs import *  # NOQA


if sys.platform.startswith("linux"):
    llvmlite.binding.load_library_permanently("libxnd.so")
elif sys.platform.startswith("darwin"):
    llvmlite.binding.load_library_permanently("libxnd.dylib")
elif sys.platform.startswith("win"):
    raise ImportWarning("Don't know how to load libxnd library on windows")
