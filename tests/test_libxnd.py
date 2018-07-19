import unittest

from xnd import xnd

import numba_xnd
from numba import njit
from numba_xnd import libndtypes, libxnd, shared
from numba_xnd.xnd import py_xnd_to_xnd, xnd_to_py_xnd

x = xnd([[1, 2, 3], [4, 5, 6]])


@njit
def subtree_single_index(py_xnd_, i):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    index.tag = libxnd.XND_KEY_INDEX
    index.Index = i
    ctx = libndtypes.create_ndt_context()
    ret = libxnd.create_xnd()
    libxnd.xnd_subtree(ret, xnd_, index, shared.i64_to_i32(1), ctx)
    return xnd_to_py_xnd(ret)


@njit
def subtree_two_ints(py_xnd_, i, j):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    index.tag = libxnd.XND_KEY_INDEX
    index.Index = i
    second_index = libxnd.get_xnd_index(index, 1)
    second_index.tag = libxnd.XND_KEY_INDEX
    second_index.Index = j
    ctx = libndtypes.create_ndt_context()
    ret = libxnd.create_xnd()
    libxnd.xnd_subtree(ret, xnd_, index, shared.i64_to_i32(2), ctx)
    return xnd_to_py_xnd(ret)


class TestSubtree(unittest.TestCase):
    def test_single_int(self):
        self.assertEqual(subtree_single_index(x, 0), x[0])

    def test_two_ints(self):
        self.assertEqual(subtree_two_ints(x, 1, 1), xnd(5))


@njit
def multikey_single_index(py_xnd_, i):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    index.tag = libxnd.XND_KEY_INDEX
    index.Index = i
    ctx = libndtypes.create_ndt_context()
    ret = libxnd.create_xnd()
    libxnd.xnd_multikey(ret, xnd_, index, shared.i32_const(1), ctx)
    return xnd_to_py_xnd(ret)


class TestMultikey(unittest.TestCase):
    def test_single_int(self):
        self.assertEqual(multikey_single_index(x, 0), x[0])


@njit
def is_equal(x, y):
    ctx = libndtypes.create_ndt_context()
    return libxnd.xnd_equal(py_xnd_to_xnd(x), py_xnd_to_xnd(y), ctx)


class TestEqual(unittest.TestCase):
    def test_arrays_equal(self):
        self.assertTrue(is_equal(xnd([1, 2, 3]), xnd([1, 2, 3])))

    def test_arrays_not_equal(self):
        self.assertFalse(is_equal(xnd([1, 2, 3]), xnd([1, 2, 4])))
