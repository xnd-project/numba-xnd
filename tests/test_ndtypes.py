import unittest

from ndtypes import ndt

import numba_xnd  # NOQA
from numba import njit

n = ndt("10 * 4 * 4 * 5 * 10 * int64")


class TestPyNdt(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(n), n)

    def test_ndim(self):
        self.assertEqual(njit(lambda x: x.ndim)(n), 5)
