import unittest

from xnd import xnd

import numba_xnd  # NOQA
from numba import njit

creators = [
    lambda: xnd(1),
    lambda: xnd([[1], [2]]),
    lambda: xnd({"hi": 1}),
    lambda: xnd({"hi": [1, 2, 3]})["hi"],
    lambda: xnd([[1, 2], [1, 2, 3]]),
    lambda: xnd(["hi", "there"]),
]


class TestXndObjectWrapper(unittest.TestCase):
    def test_boxes_unboxes(self):
        @njit
        def identity(x):
            return x

        for create in creators:
            x = create()
            with self.subTest(x=x):
                self.assertIsNot(identity(x), x)
                self.assertEqual(x, create())

    def test_type(self):
        x = xnd([[1, 2, 3], [4, 5, 6]])
        self.assertEqual(njit(lambda x: x.type.ndim)(x), x.type.ndim)

    def test_ndim(self):
        x = xnd([[1, 2, 3], [4, 5, 6]])

        self.assertEqual(njit(lambda x: x.ndim)(x), x.ndim)

    def test_value_int64(self):
        x = xnd(123)
        self.assertEqual(njit(lambda x: x.value)(x), x.value)
