import unittest

from ndtypes import ndt
from numba import njit

import numba_xnd


@njit
def is_concrete(x):
    # pylint: disable=E
    return numba_xnd.libndtypes.ndt_is_concrete(numba_xnd.libndtypes.unwrap_ndt(x))


@njit
def static_context_err():
    # pylint: disable=E
    ctx = numba_xnd.libndtypes.ndt_static_context()
    return ctx.err(0)


@njit
def get_ndim(n):
    # pylint: disable=E
    return n.ndim


@njit
def get_shape(n):
    # pylint: disable=E
    return n.shape


class TestNdt(unittest.TestCase):
    def test_static_context(self):
        self.assertFalse(static_context_err())


class TestNdtWrapper(unittest.TestCase):
    def test_ndim(self):
        self.assertEqual(get_ndim(ndt("10 * 4 * 4 * int64")), 3)

    def test_shape(self):
        self.assertEqual(get_shape(ndt("10 * 4 * 4 * int64")), (10, 4, 4))
