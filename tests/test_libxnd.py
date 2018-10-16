import unittest

import numba
from numba import njit
from xnd import xnd

import numba_xnd.libxnd
import numba_xnd.pyxnd

x = xnd([[1, 2, 3], [4, 5, 6]])

wrap_xnd_view = numba_xnd.libxnd.wrap_xnd_view
unwrap_xnd_view = numba_xnd.libxnd.unwrap_xnd_view


@njit
def is_equal(x, y):
    ctx = numba_xnd.libndtypes.ndt_static_context()
    ret = numba_xnd.libxnd.xnd_equal(
        unwrap_xnd_view(x).view(0), unwrap_xnd_view(y).view(0), ctx
    )
    numba_xnd.libndtypes.check_error(ctx, ret)
    return ret


class TestEqual(unittest.TestCase):
    def test_arrays_equal(self):
        f = xnd([1, 2, 3])
        self.assertTrue(is_equal(f, xnd([1, 2, 3])))

    def test_arrays_not_equal(self):
        self.assertFalse(is_equal(xnd([1, 2, 3]), xnd([1, 2, 4])))


class TestXndViewWrapper(unittest.TestCase):
    def test_type(self):
        x = xnd([1, 2, 3])

        @njit
        def get_type(x_wrapped):
            t_wrapped = x_wrapped.type
            return t_wrapped.ndim

        self.assertEqual(get_type(x), 1)

    def test_value_int64(self):
        @njit
        def get_value(x_wrapped):
            return x_wrapped.value

        x = xnd(123)
        self.assertEqual(get_value(x), x.value)
        self.assertEqual(x, xnd(123))

    def test_index_int(self):
        @njit
        def index_thing(a, i):
            return a[i]

        self.assertEqual(index_thing(xnd([10, 1]), 1), xnd(1))
        self.assertEqual(index_thing(xnd([10, 1]), 0), xnd(10))

    def test_index_tuple(self):
        @njit
        def index_tuple(a, i, j):
            return a[i, j].value

        x = xnd([[1, 2], [3, 4]])
        results = [((0, 0), 1), ((0, 1), 2), ((1, 0), 3), ((1, 1), 4)]
        for args, res in results:
            i, j = args
            with self.subTest(i=i, j=j):
                self.assertEqual(index_tuple(x, i, j), res)

    def test_index_tuple_empty(self):
        @njit
        def index_tuple_empty(a):
            return a[()]

        self.assertEqual(index_tuple_empty(xnd(20)), xnd(20))
