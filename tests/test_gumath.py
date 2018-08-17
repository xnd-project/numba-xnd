import unittest

from ndtypes import ndt
from xnd import xnd

import numba
import numba_xnd


@numba_xnd.gumath.register_kernel_direct(
    "integer_matrix_multiply_direct",
    "... * N * M * int64, ... * M * K * int64 -> ... * N * K * int64",
)
@numba.njit
def integer_matrix_multiply_direct(stack, ctx):
    x, y, res = stack[0], stack[1], stack[2]

    # get shape of x
    a = numba_xnd.libndtypes.create_ndt_ndarray()
    numba_xnd.libndtypes.ndt_as_ndarray(a, x.type, ctx)
    if numba_xnd.libndtypes.ndt_err_occurred(ctx):
        return -1
    n = a.shape[0]
    m = a.shape[1]

    # get shape of y
    numba_xnd.libndtypes.ndt_as_ndarray(a, y.type, ctx)
    if numba_xnd.libndtypes.ndt_err_occurred(ctx):
        return -1
    m_1 = a.shape[0]
    p = a.shape[1]
    if m_1 != m:
        return -1

    for i in range(n):
        for j in range(p):
            # we assume resulting array already initalized with zeros
            # res[i][j] = 0
            for k in range(m):
                # now we do the equivalent of this, if we had indexing
                # res[i, j] += x[i, k] * y[k, j]
                index = numba_xnd.libxnd.create_xnd_index(2)
                index.tag = numba_xnd.libxnd.XND_KEY_INDEX
                index.Index = i
                second_index = index[1]
                second_index.tag = numba_xnd.libxnd.XND_KEY_INDEX
                second_index.Index = j

                res_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    res_slice, res, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                if numba_xnd.libndtypes.ndt_err_occurred(ctx):
                    return -1

                index.Index = i
                second_index.Index = k
                x_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    x_slice, x, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                if numba_xnd.libndtypes.ndt_err_occurred(ctx):
                    return -1

                index.Index = k
                second_index.Index = j
                y_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    y_slice, y, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                if numba_xnd.libndtypes.ndt_err_occurred(ctx):
                    return -1

                res_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, res_slice.ptr
                )
                x_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, x_slice.ptr
                )
                y_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, y_slice.ptr
                )

                resulting_value = res_slice_val + (x_slice_val * y_slice_val)

                numba_xnd.shared.ptr_store_type(
                    numba.types.int64, res_slice.ptr, resulting_value
                )
    return 0


@numba_xnd.gumath.register_kernel_direct(
    "integer_add_direct", "... * int64, ... * int64 -> ... * int64"
)
@numba.njit
def integer_add_direct(stack, ctx):
    x, y, res = stack[0], stack[1], stack[2]
    x_val = numba_xnd.shared.ptr_load_type(numba.types.int64, x.ptr)
    y_val = numba_xnd.shared.ptr_load_type(numba.types.int64, y.ptr)
    numba_xnd.shared.ptr_store_type(numba.types.int64, res.ptr, x_val + y_val)
    return 0


a_p = [[1, 2, 3], [4, 5, 6]]
b_p = [[7, 8], [9, 10], [11, 12]]
res_p = [[58, 64], [139, 154]]
a = lambda: xnd(a_p)
b = lambda: xnd(b_p)
res = lambda: xnd(res_p)
a_broadcast = lambda: xnd([a_p] * 10)
b_broadcast = lambda: xnd([b_p] * 1)
res_broadcast = lambda: xnd([res_p] * 10)


class RegisterKernelDirect(unittest.TestCase):
    def test_scalar(self):
        self.assertEqual(integer_add_direct(xnd(1), xnd(2)), xnd(3))

    def test_broadcast(self):
        self.assertEqual(integer_add_direct(xnd([1, 2, 3]), xnd(2)), xnd([3, 4, 5]))

    def test_matmul(self):
        a_, b_ = a(), b()
        self.assertEqual(integer_matrix_multiply_direct(a_, b_), res())
        self.assertEqual(a_, a())
        self.assertEqual(b_, b())

    def test_matmul_broadcasting(self):
        a_, b_ = a_broadcast(), b_broadcast()
        self.assertEqual(integer_matrix_multiply_direct(a_, b_), res_broadcast())
        self.assertEqual(a_, a_broadcast())
        self.assertEqual(b_, b_broadcast())


class TestWrapKernelDispatcher(unittest.TestCase):
    def test_const_incr(self):
        @numba_xnd.gumath.register_kernel_direct("test_const_incr", "int64 -> int64")
        @numba_xnd.gumath.wrap_kernel_dispatcher(2)
        @numba.njit(
            (
                numba_xnd.libxnd.xnd_view_t.WrapperNumbaType(ndt("int64")),
                numba_xnd.libxnd.xnd_view_t.WrapperNumbaType(ndt("int64")),
            )
        )
        def something(a, ret):
            ret[()] = a.value + 10

        self.assertEqual(something(xnd(10)), xnd(20))


@numba_xnd.gumath.register_kernel(
    [
        "... * N * M * int64, ... * M * K * int64 -> ... * N * K * int64",
        "... * N * M * float64, ... * M * K * float64 -> ... * N * K * float64",
    ]
)
def simple_matrix_multiply(a, b, c):
    n, m = a.type.shape
    m_, p = b.type.shape
    for i in range(n):
        for j in range(p):
            c[i, j] = 0
            for k in range(m):
                c[i, j] = c[i, j].value + a[i, k].value * b[k, j].value


class TestRegisterKernel(unittest.TestCase):
    def test_const_incr(self):
        @numba_xnd.gumath.register_kernel("int64 -> int64")
        def something(a, ret):
            ret[()] = a.value + 10

        self.assertEqual(something(xnd(10)), xnd(20))

    def test_matmul(self):
        a_, b_ = a(), b()
        self.assertEqual(simple_matrix_multiply(a_, b_), res())
        self.assertEqual(a_, a())
        self.assertEqual(b_, b())

    def test_matmul_broadcasting(self):
        a_, b_ = a_broadcast(), b_broadcast()
        self.assertEqual(simple_matrix_multiply(a_, b_), res_broadcast())
        self.assertEqual(a_, a_broadcast())
        self.assertEqual(b_, b_broadcast())

    def test_float(self):
        a = xnd([[1.0, 1.0], [1.0, 1.0]])
        res = xnd([[2.0, 2.0], [2.0, 2.0]])
        self.assertEqual(simple_matrix_multiply(a, a), res)
