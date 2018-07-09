#include <stdio.h>
#include "ndtypes.h"
#include <stddef.h>


int main()
{
    printf("CONST_NDT_MAX_DIM = %d\n", NDT_MAX_DIM);
    printf("SIZEOF_NDT_T = %lu\n", sizeof (ndt_t));
    printf("SIZEOF_NDT_NDARRAY_T = %lu\n", sizeof (ndt_ndarray_t));
    printf("SIZEOF_NDT_CONTEXT_T = %lu\n", sizeof (ndt_context_t));
    printf("OFFSETOF_NDT_T_NDIM = %lu\n", offsetof(ndt_t, ndim));
    printf("OFFSETOF_NDT_ARRAY_T_NDIM = %lu\n", offsetof(ndt_ndarray_t, ndim));
    printf("OFFSETOF_NDT_ARRAY_T_SHAPE = %lu\n", offsetof(ndt_ndarray_t, shape));
    return 0;
}

