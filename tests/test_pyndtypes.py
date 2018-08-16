import unittest

from ndtypes import ndt

import numba_xnd  # NOQA
from numba import njit

n = ndt("10 * 4 * 4 * 5 * 10 * int64")


class TestBoxingUnboxing(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(n), n)
