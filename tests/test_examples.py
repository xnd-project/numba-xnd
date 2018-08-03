import unittest

from xnd import xnd

import numba_xnd  # NOQA
from numba import njit


@njit
def integer_const_add(a, b):
    return a.value + b.value


class SimpleAdditionTest(unittest.TestCase):
    def test_integer_addition(self):
        a = xnd(10)
        b = xnd(20)
        self.assertEqual(integer_const_add(a, b), 30)



@njit
def simple_matrix_multiply


if __name__ == "__main__":
    unittest.main()
