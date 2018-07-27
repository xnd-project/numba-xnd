import unittest

from xnd import xnd

import numba_xnd  # NOQA
from numba import njit

x = xnd([[1, 2, 3], [4, 5, 6]])
x2 = xnd({"hi": [1, 2, 3], "there": [1, 2, 3]})


@njit
def identity(x):
    return x


class TestPyXnd(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(identity(x), x)
        self.assertEqual(identity(x2), x2)
        self.assertEqual(identity(x2["hi"]), x2["hi"])

    def test_type(self):
        self.assertEqual(njit(lambda x: x.type)(x), x.type)
