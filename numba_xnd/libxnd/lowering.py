from llvmlite import ir

from numba.extending import lower_builtin, lower_getattr

from ..shared import ptr, int_
from .. import libndtypes
from . import api
from . import types
from . import llvm


@lower_getattr(types.XndType, "type")
def xnd_type_impl(context, builder, typ, value):
    get_xnd_t_type = builder.module.get_or_insert_function(
        ir.FunctionType(ptr(libndtypes.ndt_t), [ptr(llvm.xnd_t)]), name="get_xnd_t_type"
    )
    return builder.call(get_xnd_t_type, [value])
