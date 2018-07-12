from llvmlite import ir
import xnd_structinfo as xinfo

from ..shared import char

xnd_t = ir.ArrayType(char, xinfo.sizeof_xnd_t())
