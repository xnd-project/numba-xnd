import unittest

from xnd import xnd
from numba import njit

import numba_xnd
from numba_xnd import libxnd, libndtypes, shared
from numba_xnd.xnd import py_xnd_to_xnd, xnd_to_py_xnd

x = xnd([[1, 2, 3], [4, 5, 6]])


@njit
def subtree_none(py_xnd_):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    ctx = libndtypes.create_ndt_context()
    return xnd_to_py_xnd(libxnd.xnd_subtree(xnd_, index, shared.i32_const(0), ctx))


@njit
def subtree_single_index(py_xnd_, i):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    index.tag = libxnd.XND_KEY_INDEX
    index.Index = i
    ctx = libndtypes.create_ndt_context()
    return xnd_to_py_xnd(libxnd.xnd_subtree(xnd_, index, shared.i64_to_i32(1), ctx))


class TestSubtree(unittest.TestCase):
    def test_none(self):
        self.assertEqual(subtree_none(x), x)

    def test_single_int(self):
        self.assertEqual(subtree_single_index(x, 0), x[0])


@njit
def is_equal(x, y):
    ctx = libndtypes.create_ndt_context()
    return libxnd.xnd_equal(py_xnd_to_xnd(x), py_xnd_to_xnd(y), ctx)


class TestEqual(unittest.TestCase):
    def test_arrays_equal(self):
        self.assertTrue(is_equal(xnd([1, 2, 3]), xnd([1, 2, 3])))

    def test_arrays_not_equal(self):
        self.assertFalse(is_equal(xnd([1, 2, 3]), xnd([1, 2, 4])))
