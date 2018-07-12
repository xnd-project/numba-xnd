from llvmlite import ir
import xnd_structinfo as xinfo

from ..shared import char, i64

CONST_NDT_MAX_DIM = 128

ndt_t = ir.ArrayType(char, xinfo.sizeof_ndt_t())
ndt_context_t = ir.ArrayType(char, xinfo.sizeof_ndt_context_t())
ndt_ndarray_t = ir.ArrayType(char, xinfo.sizeof_ndt_ndarray_t())
ndt_ndarray_t_shape = ir.ArrayType(i64, CONST_NDT_MAX_DIM)
