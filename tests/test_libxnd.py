import unittest

from xnd import xnd

import numba
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
    ctx = numba_xnd.libndtypes.ndt_static_context()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd, xnd_object.xnd, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_xnd.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

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
    ctx = numba_xnd.libndtypes.ndt_static_context()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd, xnd_object.xnd, index, numba_xnd.shared.i64_to_i32(2), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_xnd.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

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
    ret_xnd = numba_xnd.libxnd.create_xnd()
    ctx = numba_xnd.libndtypes.ndt_static_context()
    numba_xnd.libxnd.xnd_subtree(
        ret_xnd, xnd_object.xnd, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_xnd.ptr), "ptr is not null"
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx), "ndt error"

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
        self.assertEqual(subtree_field(orig_value), xnd([[3, 4]]))
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
    ctx = numba_xnd.libndtypes.ndt_static_context()
    numba_xnd.libxnd.xnd_multikey(
        ret_xnd, xnd_object.xnd, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_xnd.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

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


class TestLoadPtr(unittest.TestCase):
    def test_bool(self):
        @njit
        def get_bool(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.boolean, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertTrue(get_bool(xnd(True)))
        self.assertFalse(get_bool(xnd(False)))

    def test_int8(self):
        @njit
        def get_int8(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int8, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_int8(xnd(10, type="int8")), 10)

    def test_int16(self):
        @njit
        def get_int16(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int16, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_int16(xnd(10, type="int16")), 10)

    def test_int32(self):
        @njit
        def get_int32(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int32, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_int32(xnd(10, type="int32")), 10)

    def test_int64(self):
        @njit
        def get_int64(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int64, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_int64(xnd(10, type="int64")), 10)

    def test_uint8(self):
        @njit
        def get_uint8(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.uint8, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_uint8(xnd(10, type="uint8")), 10)

    def test_float32(self):
        @njit
        def get_float32(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.float32, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
            )

        self.assertEqual(get_float32(xnd(10.0, type="float32")), 10.0)


class TestStorePtr(unittest.TestCase):
    def test_bool(self):
        @njit
        def set_bool(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.boolean, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr, y
            )

        x = xnd(True)
        set_bool(x, False)
        self.assertEqual(x, xnd(False))
        # self.assertTrue(get_bool(xnd(True)))

    # def test_int8(self):
    #     @njit
    #     def get_int8(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.int8, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_int8(xnd(10, type="int8")), 10)

    # def test_int16(self):
    #     @njit
    #     def get_int16(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.int16, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_int16(xnd(10, type="int16")), 10)

    # def test_int32(self):
    #     @njit
    #     def get_int32(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.int32, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_int32(xnd(10, type="int32")), 10)

    # def test_int64(self):
    #     @njit
    #     def get_int64(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.int64, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_int64(xnd(10, type="int64")), 10)

    # def test_uint8(self):
    #     @njit
    #     def get_uint8(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.uint8, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_uint8(xnd(10, type="uint8")), 10)

    # def test_float32(self):
    #     @njit
    #     def get_float32(x):
    #         return numba_xnd.shared.ptr_load_type(
    #             numba.types.float32, numba_xnd.xnd.unwrap_xnd_object(x).xnd.ptr
    #         )

    #     self.assertEqual(get_float32(xnd(10.0, type="float32")), 10.0)


# class MatrixMultiplyTest(unittest.TestCase):
#     def test_simple_example(self):
#         a = xnd([[1, 2, 3], [4, 5, 6]])
#         b = xnd([[7, 8], [9, 10], [11, 12]])
#         res = xnd([[58, 64], [139, 154]])
#         self.assertEqual(intMatMult(a, b), res)
