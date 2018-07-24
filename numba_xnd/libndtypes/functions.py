import numba
import numba.extending
import numba.targets.imputils
import numba.targets.listobj
import numba.types

from . import structs
from .. import shared

ndt_as_ndarray = shared.wrap_c_func(
    "ndt_as_ndarray",
    numba.types.int32,
    (structs.ndt_ndarray_type, structs.ndt_type, structs.ndt_context_type),
)

ndt_is_concrete = shared.wrap_c_func(
    "ndt_is_concrete", numba.types.int32, (structs.ndt_type,)
)

ndt_err_occurred = shared.wrap_c_func(
    "ndt_err_occurred", numba.types.boolean, (structs.ndt_context_type,)
)

ndt_context_msg = shared.wrap_c_func(
    "ndt_context_msg", shared.c_string_type, (structs.ndt_context_type,)
)


@shared.overload_intrinsic
def ndt_static_context():
    def impl():
        ctx = structs.create_ndt_context()
        ctx.flags = 0
        ctx.err = 0
        ctx.msg = 0
        ctx.ConstMsg = shared.c_string_const("Success")
        return ctx

    return impl


@numba.extending.intrinsic(support_literals=True)
def ndt_dim_array_to_tuple(typingctx, ndt_dim_array_t, n_t):
    if ndt_dim_array_t != structs.ndt_dim_array_type or not isinstance(
        n_t, numba.types.Const
    ):
        return

    ndim = n_t.value
    tuple_type = numba.types.Tuple([numba.types.int64] * ndim)
    sig = tuple_type(structs.ndt_dim_array_type, n_t)

    def codegen(context, builder, sig, args):
        array, _ = args
        res = context.make_tuple(
            builder, tuple_type, [builder.extract_value(array, i) for i in range(ndim)]
        )
        return numba.targets.imputils.impl_ret_new_ref(
            context, builder, tuple_type, res
        )

    return sig, codegen
