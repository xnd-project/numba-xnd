import llvmlite.ir

import numba
import numba.targets.imputils
import numba.targets.listobj
import numba.types

from .extending import create_numba_type, llvm_type_from_numba_type
from .llvm import char, i32, i64, ptr


@numba.extending.intrinsic
def i64_to_i32(typingctx, i64_t):
    if i64_t != numba.types.int64:
        return

    sig = numba.types.int32(numba.types.int64)

    def codegen(context, builder, sig, args):
        return builder.trunc(args[0], i32)

    return sig, codegen


c_string = ptr(char)
c_string_type = create_numba_type("CString", c_string)()


@numba.extending.intrinsic(support_literals=True)
def c_string_const(typingctx, str_t):
    if not isinstance(str_t, numba.types.Const):
        return

    sig = c_string_type(str_t)

    def codegen(context, builder, sig, args, str_=str_t.value):
        return context.insert_const_string(builder.module, str_)

    return sig, codegen


@numba.extending.intrinsic
def print_c_string(typingctx, c_str_t):
    sig = numba.types.int32(c_string_type)

    def codegen(context, builder, sig, args):
        return builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(i32, [c_string]), name="puts"
            ),
            args,
        )

    return sig, codegen


@numba.extending.intrinsic
def print_bytes(typingctx, ptr_t, size_t):
    """
    Prints the bytes at a certain ptr. Useful for debugging.

    C function in `structinfo_config.py` from
    https://stackoverflow.com/a/920534/907060

    It was easier for me to get this to type sucessfully if I returned an int
    instead of void, so it just returns the size passed in.
    """
    if not isinstance(size_t, numba.types.Integer):
        return
    sig = numba.types.int64(ptr_t, size_t)

    def codegen(context, builder, sig, args):
        p, s = args
        builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(llvmlite.ir.VoidType(), [ptr(char), i64]),
                name="print_bytes",
            ),
            [builder.bitcast(p, ptr(char)), s],
        )
        return s

    return sig, codegen


@numba.extending.intrinsic
def ptr_to_int(typingctx, ptr_t):
    sig = numba.types.int64(ptr_t)

    def codegen(context, builder, sig, args):
        return builder.ptrtoint(args[0], i64)

    return sig, codegen


@numba.extending.intrinsic
def ptr_is_none(typingctx, ptr_t):
    sig = numba.types.boolean(ptr_t)

    def codegen(context, builder, sig, args):
        ptr_ = args[0]
        return builder.icmp_unsigned("==", ptr_, llvmlite.ir.Constant(ptr_.type, None))

    return sig, codegen


@numba.extending.intrinsic(support_literals=True)
def literal_pyobject(typingctx, pyobject_t):
    if not isinstance(pyobject_t, numba.types.Const):
        return

    sig = numba.types.pyobject(pyobject_t)

    def codegen(context, builder, sig, args):
        return context.pyapi.unserialize(
            context.pyapi.serialize_object(pyobject_t.value)
        )

    return sig, codegen


@numba.extending.intrinsic(support_literals=True)
def ptr_load_type(typingctx, ptr_t, numba_type_t):
    """
    Called with a char* and a numba types, it will load the value  at the pointer asusming
    it is stored as LLVM version of the numa type
    """
    if ptr_t != c_string_type:
        return
    return_type = numba_type_t.instance_type
    sig = return_type(ptr_t, numba_type_t)

    def codegen(context, builder, sig, args):
        return builder.load(
            builder.bitcast(args[0], ptr(llvm_type_from_numba_type(return_type)))
        )

    return sig, codegen
