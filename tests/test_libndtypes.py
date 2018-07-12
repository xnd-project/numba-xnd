import unittest

from numba import njit
from ndtypes import ndt

# load shared libraries
import numba_xnd  # NOQA

from numba_xnd.ndtypes import py_ndt_to_ndt
from numba_xnd.libndtypes import ndt_as_ndarray, create_ndt_context, create_ndt_ndarray


n = ndt("10 * 4 * 4 * int64")


@njit
def get_ndim(x):
    c = create_ndt_context()
    a = create_ndt_ndarray()
    n = py_ndt_to_ndt(x)
    ndt_as_ndarray(a, n, c)
    return a.ndim


class TestNdt(unittest.TestCase):
    def test_ndim(self):
        self.assertEqual(get_ndim(n), 3)
