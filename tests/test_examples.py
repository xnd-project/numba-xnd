import unittest

from xnd import xnd

import numba
import numba_xnd
from numba import njit


@njit
def integer_matrix_multiply(x_p, y_p, res_p):
    x, y, res = (
        numba_xnd.pyxnd_wrapper.unwrap_xnd_object(x_p).xnd,
        numba_xnd.pyxnd_wrapper.unwrap_xnd_object(y_p).xnd,
        numba_xnd.pyxnd_wrapper.unwrap_xnd_object(res_p).xnd,
    )

    # get shape of x
    ctx = numba_xnd.libndtypes.ndt_static_context()
    a = numba_xnd.libndtypes.create_ndt_ndarray()
    numba_xnd.libndtypes.ndt_as_ndarray(a, x.type, ctx)
    # assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    n = numba_xnd.shared.array_index(a.shape, 0)
    m = numba_xnd.shared.array_index(a.shape, 1)

    # get shape of y
    numba_xnd.libndtypes.ndt_as_ndarray(a, y.type, ctx)
    # assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)
    m_1 = numba_xnd.shared.array_index(a.shape, 0)
    p = numba_xnd.shared.array_index(a.shape, 1)
    # assert m_1 == m

    for i in range(n):
        for j in range(p):
            # we assume resulting array already initalized with zeros
            # res[i][j] = 0
            for k in range(m):
                # now we do the equivalent of this, if we had indexing
                # res[i, j] += x[i, k] * y[k, j]
                index = numba_xnd.libxnd.create_xnd_index(2)
                index.tag = numba_xnd.libxnd.XND_KEY_INDEX
                index.Index = i
                second_index = index[1]
                second_index.tag = numba_xnd.libxnd.XND_KEY_INDEX
                second_index.Index = j

                res_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    res_slice, res, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                # assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

                index.Index = i
                second_index.Index = k
                x_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    x_slice, x, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                # assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

                index.Index = k
                second_index.Index = j
                y_slice = numba_xnd.libxnd.create_xnd()
                numba_xnd.libxnd.xnd_subtree(
                    y_slice, y, index, numba_xnd.shared.i64_to_i32(2), ctx
                )
                # assert not numba_xnd.libndtypes.ndt_err_occurred(ctx)

                res_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, res_slice.ptr
                )
                x_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, x_slice.ptr
                )
                y_slice_val = numba_xnd.shared.ptr_load_type(
                    numba.types.int64, y_slice.ptr
                )

                resulting_value = res_slice_val + (x_slice_val * y_slice_val)

                numba_xnd.shared.ptr_store_type(
                    numba.types.int64, res_slice.ptr, resulting_value
                )


class MatrixMultiplyTest(unittest.TestCase):
    def test_simple_example(self):
        a = xnd([[1, 2, 3], [4, 5, 6]])
        b = xnd([[7, 8], [9, 10], [11, 12]])
        res = xnd.empty("2 * 2 * int64")
        integer_matrix_multiply(a, b, res)
        self.assertEqual(res, xnd([[58, 64], [139, 154]]))


if __name__ == "__main__":
    unittest.main()
