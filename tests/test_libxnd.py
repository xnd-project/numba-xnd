import unittest

from xnd import xnd

import numba_xnd
import xnd_structinfo
from numba import njit

x = xnd([[1, 2, 3], [4, 5, 6]])

size = xnd_structinfo.sizeof_xnd_index_t()


@njit
def subtree_single_index(x, i):
    xnd_object = numba_xnd.xnd.unwrap_xnd_object(x)
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    index.Index = i
    ret_xnd = numba_xnd.libxnd.create_xnd()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd,
        xnd_object.xnd,
        index,
        numba_xnd.shared.i64_to_i32(1),
        numba_xnd.libndtypes.create_ndt_context(),
    )
    # copy the original xnd_object
    ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(xnd_object, xnd_object.type.ndt)
    ret_xnd_object.type.ndt = ret_xnd.type
    ret_xnd_object.xnd = ret_xnd
    return numba_xnd.xnd.wrap_xnd_object(ret_xnd_object)


@njit
def subtree_two_ints(x, i, j):
    xnd_object = numba_xnd.xnd.unwrap_xnd_object(x)
    index = numba_xnd.libxnd.create_xnd_index(2)
    index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    index.Index = i
    second_index = numba_xnd.libxnd.get_xnd_index(index, 1)
    second_index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    second_index.Index = j
    ret_xnd = numba_xnd.libxnd.create_xnd()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd,
        xnd_object.xnd,
        index,
        numba_xnd.shared.i64_to_i32(2),
        numba_xnd.libndtypes.create_ndt_context(),
    )
    # copy the original xnd_object
    ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(xnd_object, xnd_object.type.ndt)
    ret_xnd_object.type.ndt = ret_xnd.type
    ret_xnd_object.xnd = ret_xnd
    return numba_xnd.xnd.wrap_xnd_object(ret_xnd_object)


@njit
def subtree_field(x):
    xnd_object = numba_xnd.xnd.unwrap_xnd_object(x)
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_FIELD_NAME
    index.FieldName = numba_xnd.shared.c_string_const("there")
    numba_xnd.shared.print_bytes(index, size)
    numba_xnd.shared.print_bytes(index.FieldName, 10)
    ret_xnd = numba_xnd.libxnd.create_xnd()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd,
        xnd_object.xnd,
        index,
        numba_xnd.shared.i64_to_i32(1),
        numba_xnd.libndtypes.create_ndt_context(),
    )
    print("HI")
    assert ret_xnd.type.ndim == 1
    print("THERE")
    # copy the original xnd_object
    ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(xnd_object, xnd_object.type.ndt)
    ret_xnd_object.type.ndt = ret_xnd.type
    ret_xnd_object.xnd = ret_xnd
    return numba_xnd.xnd.wrap_xnd_object(ret_xnd_object)


class TestSubtree(unittest.TestCase):
    def test_single_int(self):
        self.assertEqual(subtree_single_index(x, 1), x[1])
        self.assertEqual(x, xnd([[1, 2, 3], [4, 5, 6]]))

    def test_two_ints(self):
        self.assertEqual(subtree_two_ints(x, 1, 1), xnd(5))
        self.assertEqual(x, xnd([[1, 2, 3], [4, 5, 6]]))

    def test_field(self):
        make_x = lambda: xnd({"hi": [1, 2], "there": [[3, 4]]})
        orig_value = make_x()
        self.assertEqual(subtree_field(orig_value), xnd([1, 2]))
        self.assertEqual(orig_value, make_x())


@njit
def multikey_slice(x, start, stop, step):
    xnd_object = numba_xnd.xnd.unwrap_xnd_object(x)
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_SLICE
    index.Slice.start = start
    index.Slice.stop = stop
    index.Slice.step = step
    ret_xnd = numba_xnd.libxnd.create_xnd()
    numba_xnd.libxnd.xnd_multikey(
        ret_xnd,
        xnd_object.xnd,
        index,
        numba_xnd.shared.i64_to_i32(1),
        numba_xnd.libndtypes.create_ndt_context(),
    )
    # copy the original xnd_object
    ret_xnd_object = numba_xnd.pyxnd.xnd_view_move_ndt(xnd_object, xnd_object.type.ndt)
    ret_xnd_object.type.ndt = ret_xnd.type
    ret_xnd_object.xnd = ret_xnd
    return numba_xnd.xnd.wrap_xnd_object(ret_xnd_object)


class TestMultikey(unittest.TestCase):
    def test_slice(self):
        x = xnd([1, 2, 3, 4, 5])
        self.assertEqual(multikey_slice(x, 0, 4, 2), x[0:4:2])
        self.assertEqual(x, xnd([1, 2, 3, 4, 5]))
        self.assertEqual(multikey_slice(xnd(list(range(10))), 2, 5, 2), xnd([2, 4]))


@njit
def is_equal(x, y):
    return numba_xnd.libxnd.xnd_equal(
        numba_xnd.xnd.unwrap_xnd_object(x).xnd,
        numba_xnd.xnd.unwrap_xnd_object(y).xnd,
        numba_xnd.libndtypes.create_ndt_context(),
    )


class TestEqual(unittest.TestCase):
    def test_arrays_equal(self):
        self.assertTrue(is_equal(xnd([1, 2, 3]), xnd([1, 2, 3])))

    def test_arrays_not_equal(self):
        self.assertFalse(is_equal(xnd([1, 2, 3]), xnd([1, 2, 4])))
