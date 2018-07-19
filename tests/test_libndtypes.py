import unittest

from ndtypes import ndt
from numba import njit
from xnd import xnd

# load shared libraries
import numba_xnd  # NOQA

from numba_xnd.ndtypes import py_ndt_to_ndt
from numba_xnd.libndtypes import ndt_as_ndarray, create_ndt_context, create_ndt_ndarray
from numba_xnd import libndtypes
from numba_xnd.xnd import py_xnd_to_xnd

n = ndt("10 * 4 * 4 * int64")


@njit
def get_ndim(x):
    c = create_ndt_context()
    a = create_ndt_ndarray()
    n = py_ndt_to_ndt(x)
    ndt_as_ndarray(a, n, c)
    return a.ndim


@njit
def is_concrete(x):
    return libndtypes.ndt_is_concrete(py_xnd_to_xnd(x).type)


class TestNdt(unittest.TestCase):
    def test_ndim(self):
        self.assertEqual(get_ndim(n), 3)

    def test_is_concrete(self):
        self.assertEqual(is_concrete(xnd([[1, 2, 3]])), 1)
