import unittest

from ndtypes import ndt
from numba import njit

import numba_xnd  # NOQA pylint: disable=W0611

n = ndt("10 * 4 * 4 * 5 * 10 * int64")


@unittest.skip("Boxing not working currently")
class TestBoxingUnboxing(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(njit(lambda x: x)(n), n)


class TestUnboxingWorks(unittest.TestCase):
    def test_unbox(self):
        self.assertEqual(njit(lambda x: None)(n), None)
