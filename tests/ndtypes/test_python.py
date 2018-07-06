import unittest

from numba import njit
from ndtypes import ndt

# register numba things
import numba_xnd.ndtypes.python


n = ndt("10 * 4 * 4 * int64")


class TestPyNdt(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(n), n)

    def test_ndim(self):
        self.assertEqual(njit(lambda x: x.ndim)(n), 3)


    def test_shape(self):
        self.assertSequenceEqual(njit(lambda x: x.shape)(n), [10, 4, 4])
