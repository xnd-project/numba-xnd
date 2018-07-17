import unittest

from numba import njit
from ndtypes import ndt

import numba_xnd


n = ndt("10 * 4 * 4 * 5 * 10 * int64")


class TestPyNdt(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(n), n)

    def test_ndim(self):
        self.assertEqual(njit(lambda x: x.ndim)(n), 5)

    def test_shape(self):
        self.assertSequenceEqual(njit(lambda x: x.shape)(n), [10, 4, 4, 5, 10])
