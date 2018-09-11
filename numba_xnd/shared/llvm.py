import llvmlite
from llvmlite import ir
from llvmlite.ir import PointerType as ptr

i8, i16, i32, i64 = map(ir.IntType, [8, 16, 32, 64])
int_ = i32
char = i8
char_ptr = ptr(char)


def index(i):
    return ir.Constant(i32, i)


def pycapsule_import(c, path, i: int, fntype, name=None):
    """
    Get's a function stored in the PyCapsule at path `path`, at index `i` with type `fntype`.

    This is based on the LLVM outputted by clang for doing this:
    https://gist.github.com/saulshanabrook/8467b10c97cc0a76ae0bcdf95a8ca478
    """
    builder = c.builder
    capsule_import = c.pyapi._get_function(
        ir.FunctionType(ptr(i8), [c.pyapi.cstring, i32]), name="PyCapsule_Import"
    )
    api_string = c.pyapi.context.insert_const_string(c.pyapi.module, path)
    xnd_api = builder.call(capsule_import, [api_string, ir.Constant(i32, 0)])

    return builder.load(
        builder.bitcast(builder.gep(xnd_api, [index(i * 8)], True), ptr(ptr(fntype))),
        name=name,
    )


def print_pointer(builder, ptr_):
    builder.call(
        builder.module.get_or_insert_function(
            llvmlite.ir.FunctionType(llvmlite.ir.VoidType(), [ptr(char)]),
            name="print_pointer",
        ),
        [ptr_],
    )
