import unittest

from xnd import xnd

import numba_xnd
from numba import njit

creators = [
    lambda: xnd(1),
    lambda: xnd([[1], [2]]),
    lambda: xnd({"hi": 1}),
    lambda: xnd({"hi": [1, 2, 3]})["hi"],
    lambda: xnd([[1, 2], [1, 2, 3]]),
    lambda: xnd(["hi", "there"]),
]


class TestViewMoveNdt(unittest.TestCase):
    def test_default_same(self):
        @njit
        def identity(x):
            return x

        for create in creators:
            x = create()
            with self.subTest(x=x):
                self.assertIs(identity(x), x)
                self.assertEqual(x, create())

    def test_wrap_unwrap_same(self):
        @njit
        def wrap_unwrap(x):
            return numba_xnd.pyxnd.wrap_xnd_object(
                numba_xnd.pyxnd.unwrap_xnd_object(x), x
            )

        for create in creators:
            x = create()
            with self.subTest(x=x):
                self.assertIs(wrap_unwrap(x), x)
                self.assertEqual(x, create())

    def test_move_new_object(self):
        @njit
        def move(x):
            xnd_object = numba_xnd.pyxnd.unwrap_xnd_object(x)
            ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(
                xnd_object, xnd_object.type.ndt
            )
            return numba_xnd.pyxnd.wrap_xnd_object(ret_xnd_object, x)

        for create in creators:
            x = create()
            with self.subTest(x=x):
                res = move(x)
                self.assertIsNot(res, x)
                self.assertEqual(res, x)
                self.assertEqual(x, create())


x = xnd([[1, 2, 3], [4, 5, 6]])
x2 = xnd({"hi": [1, 2, 3], "there": [1, 2, 3]})


@njit
def identity(x):
    return x


class TestXndObjectWrapper(unittest.TestCase):
    def test_boxes_unboxes(self):
        self.assertEqual(identity(x), x)
        self.assertEqual(identity(x2), x2)
        self.assertEqual(identity(x2["hi"]), x2["hi"])

    def test_type(self):
        self.assertEqual(njit(lambda x: x.type)(x), x.type)

    def test_ndim(self):
        self.assertEqual(njit(lambda x: x.ndim)(x), x.ndim)

    def test_value_int64(self):
        x = xnd(123)
        self.assertEqual(njit(lambda x: x.value)(x), x.value)
