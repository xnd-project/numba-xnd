import unittest

from ndtypes import ndt

import numba_xnd
from numba import njit

n = ndt("10 * 4 * 4 * int64")


@njit
def get_ndim(x):
    return numba_xnd.libndtypes.unwrap_ndt(x).ndim


@njit
def get_shape(x):
    a = numba_xnd.libndtypes.create_ndt_ndarray()
    numba_xnd.libndtypes.ndt_as_ndarray(
        a, numba_xnd.libndtypes.unwrap_ndt(x), numba_xnd.libndtypes.create_ndt_context()
    )
    return (a.shape[0], a.shape[1], a.shape[2])


@njit
def is_concrete(x):
    return numba_xnd.libndtypes.ndt_is_concrete(numba_xnd.libndtypes.unwrap_ndt(x))


class TestNdt(unittest.TestCase):
    def test_ndim(self):
        self.assertEqual(get_ndim(n), 3)

    def test_shape(self):
        self.assertEqual(get_shape(n), (10, 4, 4))

    def test_is_concrete(self):
        self.assertEqual(is_concrete(n), 1)

    def test_static_context(self):
        @njit
        def static_context():
            ctx = numba_xnd.libndtypes.ndt_static_context()
            assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

        static_context()


class TestNdtWrapper(unittest.TestCase):
    def test_ndim(self):
        @njit
        def get_ndim(t_object_wrapper):
            t = numba_xnd.libndtypes.unwrap_ndt(t_object_wrapper)
            t_wrapper = numba_xnd.libndtypes.wrap_ndt(t, t_object_wrapper)
            return t_wrapper.ndim

        self.assertEqual(get_ndim(n), 3)

    def test_shape(self):
        @njit
        def get_shape(t_object_wrapper):
            t = numba_xnd.libndtypes.unwrap_ndt(t_object_wrapper)
            t_wrapper = numba_xnd.libndtypes.wrap_ndt(t, t_object_wrapper)
            return t_wrapper.shape

        self.assertEqual(get_shape(n), (10, 4, 4))
