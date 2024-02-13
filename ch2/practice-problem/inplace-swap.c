// inplace-swap.c
#include "inplace-swap.h"

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y; // step 1
    *x = *x ^ *y; // step 2
    *y = *x ^ *y; // step 3
}