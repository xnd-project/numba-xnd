import llvmlite
import llvmlite.ir
import ndtypes
import numba
import numba.extending
import numba.targets.imputils
import numba.targets.listobj
import numba.types

from . import shared

llvmlite.binding.load_library_permanently(ndtypes._ndtypes.__file__)


NDT_MAX_DIM = 128


class NdtType(
    shared.CStructType,
    c_name="ndt_t",
    attrs={"ndim": numba.types.int32, "tag": numba.types.int64},
):
    pass


class NdtWrapperType(shared.WrapperType, inner_type=NdtType):
    pass


wrap_ndt, unwrap_ndt = NdtWrapperType.wrap, NdtWrapperType.unwrap


class NdtNdarrayType(
    shared.CStructType,
    c_name="ndt_ndarray_t",
    attrs={
        "ndim": numba.types.int32,
        "shape": numba.types.UniTuple(numba.types.int64, NDT_MAX_DIM),
    },
):
    pass


alloc_ndt_ndarray = NdtNdarrayType.alloc


class NdtSliceType(
    shared.CStructType,
    c_name="ndt_slice_t",
    attrs={
        "start": numba.types.int64,
        "stop": numba.types.int64,
        "step": numba.types.int64,
    },
):
    pass


class NdtContextType(
    shared.CStructType,
    c_name="ndt_context_t",
    attrs={
        "flags": numba.types.uint32,
        "err": numba.types.int32,
        "msg": numba.types.int32,
        "ConstMsg": shared.c_string_type,
        "DynamicMsg": shared.c_string_type,
    },
):
    pass


alloc_ndt_context = NdtContextType.alloc


ndt_as_ndarray = shared.CFunctionIntrinsic(
    "ndt_as_ndarray", numba.types.int32, (NdtNdarrayType, NdtType, NdtContextType)
)

ndt_is_concrete = shared.CFunctionIntrinsic(
    "ndt_is_concrete", numba.types.int32, (NdtType,)
)

ndt_err_occurred = shared.CFunctionIntrinsic(
    "ndt_err_occurred", numba.types.boolean, (NdtContextType,)
)

ndt_context_msg = shared.CFunctionIntrinsic(
    "ndt_context_msg", shared.c_string_type, (NdtContextType,)
)

ndt_err_fprint_stdout = shared.CFunctionIntrinsic(
    "ndt_err_fprint_stdout", numba.types.void, (NdtContextType,)
)


@numba.njit
def ndt_static_context():
    # pylint: disable=E
    ctx = alloc_ndt_context(1)
    ctx.flags(0, 0)
    ctx.err(0, 0)
    ctx.msg(0, 0)
    ctx.ConstMsg(0, shared.c_string_const("Success"))
    return ctx


@numba.njit
def set_error(ctx):
    ndt_err_fprint_stdout(ctx)
    raise RuntimeError("Error in ndt context")


@numba.njit
def check_error(ctx, ptr_):
    if shared.ptr_is_none(ptr_):
        set_error(ctx)


@numba.extending.overload_attribute(NdtWrapperType, "shape")
def ndt_wrapper_shape(t):
    ndim = shared.get_ndim(t.ndt_value)

    def get(t):
        # pylint: disable=E
        a = alloc_ndt_ndarray(1)
        ctx = ndt_static_context()
        ndt_as_ndarray(a, unwrap_ndt(t), ctx)
        if ndt_err_occurred(ctx):
            shared.print_c_string(ndt_context_msg(ctx))
            raise RuntimeError("ndt_as_ndarray failed.")
        return a.shape(0)[:ndim]

    return get


@numba.extending.overload_attribute(NdtWrapperType, "ndim")
def ndt_wrapper_ndim(t):
    ndim = shared.get_ndim(t.ndt_value)

    def get(t):
        return ndim

    return get
