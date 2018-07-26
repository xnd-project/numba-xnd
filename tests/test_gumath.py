import unittest

from xnd import xnd

import numba
import numba_xnd


@numba_xnd.register_gumath_kernel(
    "integer_add", "... * int64, ... * int64 -> ... * int64"
)
@numba.njit
def integer_add(stack, ctx):
    x, y, res = stack[0], stack[1], stack[2]
    x_val = numba_xnd.shared.ptr_load_type(numba.types.int64, x.ptr)
    y_val = numba_xnd.shared.ptr_load_type(numba.types.int64, y.ptr)
    numba_xnd.shared.ptr_store_type(numba.types.int64, res.ptr, x_val + y_val)
    return 0


class RegisterKernelTest(unittest.TestCase):
    def test_scalar(self):
        self.assertEqual(integer_add(xnd(1), xnd(2)), xnd(3))

    def test_broadcast(self):
        self.assertEqual(integer_add(xnd([1, 2, 3]), xnd(2)), xnd([3, 4, 5]))
