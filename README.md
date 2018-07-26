# Numba integration for XND

[![CircleCI branch](https://img.shields.io/circleci/project/github/Quansight/numba-xnd/master.svg)](https://circleci.com/gh/Quansight/workflows/numba-xnd/tree/master)
[![Codecov branch](https://img.shields.io/codecov/c/github/quansight/numba-xnd/master.svg)](https://codecov.io/gh/quansight/numba-xnd)
[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/ambv/black)

## Usage

```python
from numba import jit
from xnd import xnd

# register types
import numba_xnd


@jit(nopython=True)
def shape_and_ndim(x):
    return x.type.shape, x.type.ndim


x = xnd([[1, 2], [4, 5]])
assert shape_and_ndim(x) == ([3, 4], 2)
```

## Development

```bash
conda env create
conda activate numba-xnd
cd numba
python setup.py develop
cd ..
python setup.py develop
# ready to run project scripts
```

Run tests:

```python
python -m unittest
```

Updating `xnd_structinfo.c`:

```bash
pip install git+https://github.com/plures/xndtools.git
structinfo_generator structinfo_config.py
```

## Project Structure

The directory structure is meant to mirror the `plures/*` projects. For each plures project,
We have the low level API wrapping the C library (`./libndtypes`) and then a higher level API
wrapping the python level (`./ndtypes`). The Python level should use the functions
in the C level.

For the Python API, we implement lowering some of the same functions/methods that are present at the normal python level, so that a user who wraps a functions in `jit` will have the same API.

## Design Notes

Goals:

- Provide users with a way to operate on xnd structures in python that has fast performance

Approach:

- Register xnd properly in numba so that we use the numba machinery to extract intent from python code user writes and compile to LLVM
- allow taking numba jitted function and creating gumath kernel from it

Assumptions:

- The numba API should be the same as the python API. So that the user can write code and use
  it either jit compiled or not
- All operations we should support should be able to done in nopython mode

Open questions:

- Should numba types for xnd include shape information? What if some shapes are not known until runtime?
  - If we have compile time shape information, then we maybe we shouldn't use libxnd's indexing functions, because these are not shape aware.
    They have to introspect shapes at runtime, so the code won't be as optimized as if we produced llvm for the specific dimensions we have. - **SOLUTION**: We have low level code that has no typing information. We can always fall back to this for flexbility. Them, using that, we build high level API with typing information that can be more optimized and have a better UI
  - Is it possible in numba to go back and forth between lowered and unlowered code? Erm, I mean like if we know some partial shape information for the program
    can we execute part of it, then use that resulting shape information to re-compile the rest? I guess this would be too slow.
    - **SOLUTION**: We can't do this. See above.
- How do we get garbage collection/memory allocation working?
  - Do we use the `xnd_master_t` struct?
    - **SOLUTION**: Don't worry about this for now. Forget xnd_master_t
- Should we be using numba's array type? That we can get all the optimizations they have built in for it.
  - I am leaning towards no, since it might be hard to extend to fit xnd's model
    - **SOLUTION**: Yeah, don't use Numba's array. Eventually we should refactor their array support to be able to
      support other data types. They want to do this anyway.

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
