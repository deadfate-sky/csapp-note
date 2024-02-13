#include <stdio.h>
#include "inplace-swap.h"

void origin_reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1;
         first <= last;
         first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1;
         first < last;
         first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

int main(int argc, char *argv[])
{
    int z = 5;
    inplace_swap(&z, &z);
    printf("z: %d\n", z);

    // check the `inplace_swap` function
    int x = 5, y = 10;
    printf("original x, y: %d, %d\n", x, y);
    inplace_swap(&x, &y);
    printf("after swap: %d, %d\n", x, y);

    // check the wrong of origin function
    int a1[] = {1, 2, 3, 4, 5};
    printf("Original array (wrong): ");
    for (int i = 0; i < 5; i++)
        printf("%d ", a1[i]);
    int length1 = sizeof(a1) / sizeof(a1[0]);
    origin_reverse_array(a1, length1);
    printf("\nReversed array (wrong): ");
    for (int i = 0; i < length1; i++)
        printf("%d ", a1[i]);
    printf("\n");

    // use the `reverse_array` function
    int a[] = {1, 2, 3, 4, 5};
    printf("Original array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    int length = sizeof(a) / sizeof(a[0]);
    reverse_array(a, length);
    printf("Reversed array: ");
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}