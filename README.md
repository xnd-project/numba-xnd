# Numba integration for XND

Goals:

* Provide users with a way to operate on xnd structures in python that has fast performance

Approach:

* Register xnd properly in numba so that we use the numba machinery to extract intent from python code user writes and compile to LLVM
* allow taking numba jitted function and creating gumath kernel from it

Assumptions:

* The numba API should be the same as the python API. So that the user can write code and use
  it either jit compiled or not
* All operations we should support should be able to done in nopython mode

Open questions:

* Should numba types for xnd include shape information? What if some shapes are not known until runtime?
  * If we have compile time shape information, then we maybe we shouldn't use libxnd's indexing functions, because these are not shape aware.
    They have to introspect shapes at runtime, so the code won't be as optimized as if we produced llvm for the specific dimensions we have.
  * Is it possible in numba to go back and forth between lowered and unlowered code? Erm, I mean like if we know some partial shape information for the program
    can we execute part of it, then use that resulting shape information to re-compile the rest? I guess this would be too slow.
* How do we get garbage collection/memory allocation working?
  * Do we use the `xnd_master_t` struct?
* Should we be using numba's array type? That we can get all the optimizations they have built in for it.
  * I am leaning towards no, since it might be hard to extend to fit xnd's model

Current status:

There is some code that implements parts of this in `quansight/numba@xnd`, but it converts xnd to numpy like arrays
for the gumath kernel creation. Instead we should keep everything as xnd types, so we get the full flexibility of the type system.

API:

Allows simple for indexing xnd types:

```python
@jit(nopython=True)
def sum_1d(a):
    c = 0
    for i in range(a.type.shape[0]):
        c += a[i]
    return c

assert sum_1d(xnd([1, 2, 3])) == 6

@jit(nopython=True)
def sum_attr(a):
    c = 0
    for i in range(a.type.shape[0]):
        c += a[i]['hi']
    return c

assert sum_attr(xnd([{'hi': 1}, {'hi': 2}])) == 3
```

Any jitted function that takes in all xnd argument and returns xnd arguments
can be registered as an gumath kernel.

Can create gumath kernels. The last argument is always the return value:

```python
@register_gumath_kernel([
    'N * M * float64, M * P * float64 -> M * P * float64',
    'N * M * int64, M * P * int64 -> M * P * int64'
])
@jit(nopython=True)
def matrix_multiply(a, b, c):
    n, m = a.type.shape
    m, p = b.type.shape
    for i in range(n):
        for j in range(p):
            c[i][j] = 0
            for k in range(m):
                c[i][j] += a[i][k] * b[k][j]

assert len(matrix_multiply.kernels) == 2
```

Can also create them with runtime type inspect:

```python
@register_gumath_kernel
@jit(nopython=True)
def add(a, b, c):
    c[tuple()] = xnd(a[tuple()] + b[tuple()]

add(xnd(1), xnd(2))
```

## Development

```bash
conda env create -f environment.yml
conda activate numba-xnd
cd numba
python setup.py develop
cd ..
# ready to run project scripts
```

Calculate sizes

```bash
clang $(python-config --includes) sizes.c -o sizes
./sizes
```
