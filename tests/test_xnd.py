import unittest

from xnd import xnd

import numba_xnd
from numba import njit

x = xnd([[1, 2, 3], [4, 5, 6]])


class TestPyXnd(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(x), x)

    def test_type(self):
        self.assertEqual(njit(lambda x: x.type)(x), x.type)

    # def test_shape(self):
    #     self.assertSequenceEqual(njit(lambda x: x.shape)(n), [10, 4, 4])
