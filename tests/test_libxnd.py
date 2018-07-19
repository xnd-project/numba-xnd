import unittest

from numba import njit
from xnd import xnd

import numba_xnd
from numba_xnd import libxnd, libndtypes, shared
from numba_xnd.xnd import py_xnd_to_xnd

x = xnd([[1, 2, 3], [4, 5, 6]])


@njit
def subtree_single_index(py_xnd_, i):
    xnd_ = py_xnd_to_xnd(py_xnd_)
    index = libxnd.create_xnd_index()
    index.tag = libxnd.XND_KEY_INDEX
    index.Index = i
    ctx = libndtypes.create_ndt_context()
    return libxnd.xnd_subtree(xnd_, index, shared.i64_to_i32(1), ctx)


class TestSubtree(unittest.TestCase):
    def test_single_int(self):
        self.assertEqual(subtree_single_index(x, 0), x[0])

    # def test_type(self):
    #     self.assertEqual(njit(lambda x: x.type)(x), x.type)

    # def test_shape(self):
    #     self.assertSequenceEqual(njit(lambda x: x.shape)(n), [10, 4, 4])
