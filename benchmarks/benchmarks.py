from xnd import xnd

import numba_xnd


def simple_matrix_multiply(a, b, c):
    n, m = a.type.shape
    m_, p = b.type.shape
    for i in range(n):
        for j in range(p):
            c[i, j] = 0
            for k in range(m):
                c[i, j] = c[i, j].value + a[i, k].value * b[k, j].value


kernel = numba_xnd.register_kernel(
    "... * N * M * int64, ... * M * K * int64 -> ... * N * K * int64"
)(simple_matrix_multiply)


class TimeSuite:
    params = ("kernel", "xnd")

    def setup(self, type_):
        self.a = xnd.empty("100 * 100 * int64")
        self.b = xnd.empty("100 * 100 * int64")
        self.res = xnd.empty("100 * 100 * int64")

        self.broad_a = xnd.empty("1000 * 10 * 10 * int64")
        self.broad_b = xnd.empty("1000 * 10 * 10 * int64")
        self.broad_res = xnd.empty("1000 * 10 * 10 * int64")

    def time_single(self, type_):
        if type_ == "xnd":
            simple_matrix_multiply(self.a, self.b, self.res)
        else:
            kernel(self.a, self.b)

    def time_broadcasting(self, type_):
        if type_ == "xnd":
            for i in range(1000):
                simple_matrix_multiply(
                    self.broad_a[i], self.broad_b[i], self.broad_res[i]
                )
        else:
            kernel(self.broad_a, self.broad_b)
