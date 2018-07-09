from llvmlite import ir
from ..shared import sizes, llvm as shared_llvm

ndt_t = ir.ArrayType(shared_llvm.char, sizes.SIZEOF_NDT_T)
ndt_context_t = ir.ArrayType(shared_llvm.char, sizes.SIZEOF_NDT_CONTEXT_T)
ndt_ndarray_t = ir.ArrayType(shared_llvm.char, sizes.SIZEOF_NDT_NDARRAY_T)
