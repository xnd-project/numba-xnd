import llvmlite.ir

import numba
import numba.targets.imputils
import numba.targets.listobj
import numba.types

from .extending import create_numba_type
from .llvm import i32, i64, ptr

integer_list = ptr(i64)
integer_list_type = create_numba_type("IntegerList", integer_list)()


@numba.extending.intrinsic
def integer_list_to_python_list(typingctx, integer_list_t, n_t):
    if integer_list_t != integer_list_type or n_t != numba.types.int32:
        return

    list_type = numba.types.List(numba.types.int64)
    sig = list_type(integer_list_type, numba.types.int32)

    def codegen(context, builder, sig, args):
        array, ndim = args
        ndim = builder.sext(ndim, i64)
        inst = numba.targets.listobj.ListInstance.allocate(
            context, builder, list_type, ndim
        )
        inst.size = ndim
        with numba.cgutils.for_range(builder, ndim) as loop:
            i = loop.index
            inst.setitem(
                idx=i,
                val=builder.load(builder.gep(array, [i])),
                incref=True,  # no idea what incref does
            )

        return numba.targets.imputils.impl_ret_new_ref(
            context, builder, list_type, inst.value
        )

    return sig, codegen


@numba.extending.intrinsic
def i64_to_i32(typingctx, i64_t):
    if i64_t != numba.types.int64:
        return

    sig = numba.types.int32(numba.types.int64)

    def codegen(context, builder, sig, args):
        return builder.trunc(args[0], i32)

    return sig, codegen


@numba.extending.intrinsic(support_literals=True)
def i32_const(typingctx, i_t):
    if not isinstance(i_t, numba.types.Const):
        return

    sig = numba.types.int32(numba.types.int64)

    def codegen(context, builder, sig, args):
        return llvmlite.ir.Constant(i32, i_t.value)

    return sig, codegen
