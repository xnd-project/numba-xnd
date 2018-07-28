import unittest

from ndtypes import ndt

import numba_xnd
from numba import njit

n = ndt("10 * 4 * 4 * int64")


@njit
def get_ndim(x):
    return numba_xnd.pyndtypes_wrapper.unwrap_ndt_object(x).ndt.ndim


@njit
def get_shape(x):
    a = numba_xnd.libndtypes.create_ndt_ndarray()
    numba_xnd.libndtypes.ndt_as_ndarray(
        a,
        numba_xnd.pyndtypes_wrapper.unwrap_ndt_object(x).ndt,
        numba_xnd.libndtypes.create_ndt_context(),
    )
    return (
        numba_xnd.shared.array_index(a.shape, 0),
        numba_xnd.shared.array_index(a.shape, 1),
        numba_xnd.shared.array_index(a.shape, 2),
    )


@njit
def is_concrete(x):
    return numba_xnd.libndtypes.ndt_is_concrete(
        numba_xnd.pyndtypes_wrapper.unwrap_ndt_object(x).ndt
    )


class TestNdt(unittest.TestCase):
    def test_ndim(self):
        self.assertEqual(get_ndim(n), 3)

    def test_shape(self):
        self.assertEqual(get_shape(n), (10, 4, 4))

    def test_is_concrete(self):
        self.assertEqual(is_concrete(n), 1)
