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
            return numba_xnd.xnd.wrap_xnd_object(
                numba_xnd.xnd.unwrap_xnd_object(x), x.type
            )

        for create in creators:
            x = create()
            with self.subTest(x=x):
                self.assertIs(wrap_unwrap(x), x)
                self.assertEqual(x, create())

    def test_move_new_object(self):
        @njit
        def move(x):
            xnd_object = numba_xnd.xnd.unwrap_xnd_object(x)
            ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(
                xnd_object, xnd_object.type.ndt
            )
            return numba_xnd.xnd.wrap_xnd_object(ret_xnd_object, x.type)

        for create in creators:
            x = create()
            with self.subTest(x=x):
                res = move(x)
                self.assertIsNot(res, x)
                self.assertEqual(res, x)
                self.assertEqual(x, create())
