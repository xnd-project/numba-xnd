"""
Helpers for xnd/ndtypes/gumath that could eventually be added to their python apis
"""

import random

import ndtypes


def remove_outer_dimensions(t, n):
    """
    Remove `n` outer dimensions from type `t`.
    """
    return ndtypes.ndt(" * ".join(str(t).split(" * ")[n:]))


def random_kernel_name(n=30):
    """
    Returns a random string of letters of length `n` that works as a gumath kernel name.
    """
    return "".join(chr(random.randrange(ord("a"), ord("z"))) for _ in range(n))


def sig_to_stack(t):
    """
    Takes in a ndtypes signature and returns a list of the types for the xnd objects
    on the stack passed into the gumath kernel.

    >>> sig_to_stack(ndtypes.ndt("... * int64, ... * N * int64 -> float64, int64"))
    (ndtypes.ndt("int64"), ndtypes.ndt("N * int64"), ndtypes.ndt("float64"), ndtypes.ndt("int64"))
    """
    args, rets = str(t).split(" -> ")
    stacks = tuple()
    for v in args.split(", ") + rets.split(", "):
        stacks += (
            ndtypes.ndt(" * ".join(d for d in v.split(" * ") if "..." not in d)),
        )
    return stacks


def get_ndim(t):
    """
    Returns the number of dimensions in a ndtypes signature. Can be abstract.

    >>> get_ndim(ndtypes.ndt("10 * 4 * int64"))
    2
    >>> get_ndim(ndtypes.ndt("N * K * int64"))
    2
    """
    return str(t).count(" * ")
