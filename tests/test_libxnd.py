import unittest

from xnd import _xnd, xnd

import numba
import numba_xnd
import xnd_structinfo
from numba import njit

x = xnd([[1, 2, 3], [4, 5, 6]])


@njit
def subscript_single_index(x_wrapped, i):
    x = numba_xnd.libxnd.unwrap_xnd_view_mem_info(x_wrapped).data
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    index.Index = i
    ctx = numba_xnd.libndtypes.ndt_static_context()
    ret_x_v_mi = numba_xnd.libxnd.create_xnd_view_mem_info()
    numba_xnd.libxnd.xnd_view_subscript(
        ret_x_v_mi, x, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_x_v_mi.data.view.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    return numba_xnd.libxnd.wrap_xnd_view_mem_info_mem_info(ret_x_v_mi, x_wrapped)


@njit
def subscript_two_ints(x_wrapped, i, j):
    x = numba_xnd.libxnd.unwrap_xnd_view_mem_info(x_wrapped).data
    index = numba_xnd.libxnd.create_xnd_index(2)
    index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    index.Index = i
    second_index = index[1]
    second_index.tag = numba_xnd.libxnd.XND_KEY_INDEX
    second_index.Index = j
    ctx = numba_xnd.libndtypes.ndt_static_context()
    ret_x_v_mi = numba_xnd.libxnd.create_xnd_view_mem_info()
    numba_xnd.libxnd.xnd_view_subscript(
        ret_x_v_mi, x, index, numba_xnd.shared.i64_to_i32(2), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_x_v_mi.data.view.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    return numba_xnd.libxnd.wrap_xnd_view_mem_info_mem_info(ret_x_v_mi, x_wrapped)


@njit
def subscript_field(x_wrapped):
    x = numba_xnd.libxnd.unwrap_xnd_view_mem_info(x_wrapped).data
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_FIELD_NAME
    index.FieldName = numba_xnd.shared.c_string_const("there")
    ctx = numba_xnd.libndtypes.ndt_static_context()
    ret_x_v_mi = numba_xnd.libxnd.create_xnd_view_mem_info()

    numba_xnd.libxnd.xnd_view_subscript(
        ret_x_v_mi, x, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_x_v_mi.data.view.ptr), "ptr is not null"
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx), "ndt error"

    return numba_xnd.libxnd.wrap_xnd_view_mem_info(ret_x_v_mi, x_wrapped)


@njit
def subscript_slice(x_wrapped, start, stop, step):
    x = numba_xnd.libxnd.unwrap_xnd_view_mem_info(x_wrapped).data
    index = numba_xnd.libxnd.create_xnd_index()
    index.tag = numba_xnd.libxnd.XND_KEY_SLICE
    index.Slice.start = start
    index.Slice.stop = stop
    index.Slice.step = step
    ctx = numba_xnd.libndtypes.ndt_static_context()
    ret_x_v_mi = numba_xnd.libxnd.create_xnd_view_mem_info()
    numba_xnd.libxnd.xnd_view_subscript(
        ret_x_v_mi, x, index, numba_xnd.shared.i64_to_i32(1), ctx
    )
    assert not numba_xnd.shared.ptr_is_none(ret_x_v_mi.data.view.ptr)
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    return numba_xnd.libxnd.wrap_xnd_view_mem_info(ret_x_v_mi, x_wrapped)


class TestViewSubscript(unittest.TestCase):
    def test_single_int(self):
        self.assertEqual(subscript_single_index(x, 1), x[1])
        self.assertEqual(x, xnd([[1, 2, 3], [4, 5, 6]]))

    def test_two_ints(self):
        self.assertEqual(subscript_two_ints(x, 1, 1), xnd(5))
        self.assertEqual(x, xnd([[1, 2, 3], [4, 5, 6]]))

    def test_field(self):
        def make_x():
            return xnd({"hi": [1, 2], "there": [[3, 4]]})

        orig_value = make_x()
        self.assertEqual(subscript_field(orig_value), xnd([[3, 4]]))
        self.assertEqual(orig_value, make_x())

    def test_slice(self):
        x = xnd([1, 2, 3, 4, 5])
        self.assertEqual(subscript_slice(x, 0, 4, 2), x[0:4:2])
        self.assertEqual(x, xnd([1, 2, 3, 4, 5]))
        self.assertEqual(subscript_slice(xnd(list(range(10))), 2, 5, 2), xnd([2, 4]))


@njit
def is_equal(x, y):
    print("STARTING")
    x_xnd_view_mem_info = numba_xnd.libxnd.unwrap_xnd_view_mem_info(x)
    y_xnd_view_mem_info = numba_xnd.libxnd.unwrap_xnd_view_mem_info(y)
    print("X_SIZE", x_xnd_view_mem_info.size, x_xnd_view_mem_info.refct)
    print("Y_SIZE", y_xnd_view_mem_info.size)
    print("flags", x_xnd_view_mem_info.data.flags)
    # print("obj", numba_xnd.shared.ptr_to_int(x_xnd_view_mem_info.data.obj))
    x_ = x_xnd_view_mem_info.data.view
    y_ = y_xnd_view_mem_info.data.view
    # print("x_ptr", numba_xnd.shared.ptr_to_int(x_))
    # print("ndim", x_.type.ndim)
    # print(numba_xnd.shared.ptr_to_int(x_), numba_xnd.shared.ptr_to_int(y_))
    # print(numba_xnd.shared.ptr_to_int(x_.ptr), numba_xnd.shared.ptr_to_int(y_.ptr))
    ctx = numba_xnd.libndtypes.ndt_static_context()
    print("STRATING EQUAL")
    ret = numba_xnd.libxnd.xnd_equal(x_, y_, ctx)
    print("done EQUAL")
    assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    print("NO ERROR")
    return ret


class TestEqual(unittest.TestCase):
    def test_arrays_equal(self):
        f = xnd([1, 2, 3])
        print("id", id(f))

        print(
            "XND",
            xnd_structinfo.value_int64(
                xnd_structinfo.get_XndObject_xnd(
                    xnd_structinfo.capsulate_XndObject(
                        _xnd.Xnd(value=f.value, type=f.type)
                    )
                )
            ),
        )
        self.assertTrue(is_equal(f, xnd([1, 2, 3])))

    def test_arrays_not_equal(self):
        self.assertFalse(is_equal(xnd([1, 2, 3]), xnd([1, 2, 4])))


class TestLoadPtr(unittest.TestCase):
    def test_bool(self):
        @njit
        def get_bool(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.boolean,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertTrue(get_bool(xnd(True)))
        self.assertFalse(get_bool(xnd(False)))

    def test_int8(self):
        @njit
        def get_int8(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int8,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_int8(xnd(10, type="int8")), 10)

    def test_int16(self):
        @njit
        def get_int16(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int16,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_int16(xnd(10, type="int16")), 10)

    def test_int32(self):
        @njit
        def get_int32(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int32,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_int32(xnd(10, type="int32")), 10)

    def test_int64(self):
        @njit
        def get_int64(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.int64,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_int64(xnd(10, type="int64")), 10)

    def test_uint8(self):
        @njit
        def get_uint8(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.uint8,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_uint8(xnd(10, type="uint8")), 10)

    def test_float32(self):
        @njit
        def get_float32(x):
            return numba_xnd.shared.ptr_load_type(
                numba.types.float32,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
            )

        self.assertEqual(get_float32(xnd(10.0, type="float32")), 10.0)


class TestStorePtr(unittest.TestCase):
    def test_bool(self):
        @njit
        def set_bool(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.boolean,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(True)
        set_bool(x, False)
        self.assertEqual(x, xnd(False))
        set_bool(x, True)
        self.assertEqual(x, xnd(True))

    def test_int8(self):
        @njit
        def set_int8(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.int8,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(123, type="int8")
        set_int8(x, 10)
        self.assertEqual(x, xnd(10, type="int8"))

    def test_int16(self):
        @njit
        def set_int16(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.int16,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(123, type="int16")
        set_int16(x, 10)
        self.assertEqual(x, xnd(10, type="int16"))

    def test_int32(self):
        @njit
        def set_int32(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.int32,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(123, type="int32")
        set_int32(x, 10)
        self.assertEqual(x, xnd(10, type="int32"))

    def test_uint8(self):
        @njit
        def set_uint8(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.uint8,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(123, type="uint8")
        set_uint8(x, 10)
        self.assertEqual(x, xnd(10, type="uint8"))

    def test_float32(self):
        @njit
        def set_float32(x, y):
            numba_xnd.shared.ptr_store_type(
                numba.types.float32,
                numba_xnd.libxnd.unwrap_xnd_view_mem_info(x).data.view.ptr,
                y,
            )

        x = xnd(123.123, type="float32")
        set_float32(x, 10.0)
        self.assertEqual(x, xnd(10.0, type="float32"))


class TestXndViewWrapper(unittest.TestCase):
    def test_type(self):
        x = xnd([1, 2, 3])

        @njit
        def get_type(x_wrapped):
            t_wrapped = x_wrapped.type
            return t_wrapped.ndim

        self.assertEqual(get_type(x), 1)

    def test_value_int64(self):
        @njit
        def get_value(x_wrapped):
            return x_wrapped.value

        x = xnd(123)
        self.assertEqual(get_value(x), x.value)
        self.assertEqual(x, xnd(123))

    def test_index_int(self):
        @njit
        def index_thing(a, i):
            return a[i]

        self.assertEqual(index_thing(xnd([10, 1]), 1), xnd(1))
        self.assertEqual(index_thing(xnd([10, 1]), 0), xnd(10))

    def test_index_tuple(self):
        @njit
        def index_tuple(a, i, j):
            return a[i, j].value

        x = xnd([[1, 2], [3, 4]])
        results = [((0, 0), 1), ((0, 1), 2), ((1, 0), 3), ((1, 1), 4)]
        for args, res in results:
            i, j = args
            with self.subTest(i=i, j=j):
                self.assertEqual(index_tuple(x, i, j), res)

    def test_index_tuple_empty(self):
        @njit
        def index_tuple_empty(a):
            return a[()]

        self.assertEqual(index_tuple_empty(xnd(20)), xnd(20))
