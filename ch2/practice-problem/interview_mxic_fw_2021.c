#include <stdio.h>
#include <stdlib.h>
// int32_t z = x ^ y;
// int32_t count = 0;
// while (z)
// {
//     count += z & 1;
//     z >>= 1;
// }
// return count;

int compare_int32(int32_t x, int32_t y)
{
    int32_t z = x ^ y; // this exclusive-or step could find which bit is different.
    int32_t count = 0;
    while (z)
    {
        count += z & 1; // if the last bit of z is 1, then count + 1
        z >>= 1;        // shift right 1 bit
    }
    // return how many bits are different between x and y
    return count;
}

int main(int argc, char *argv[])
{
    int32_t x = (int32_t)strtol(argv[1], NULL, 10);
    int32_t y = (int32_t)strtol(argv[2], NULL, 10);
    printf("x: %d, y: %d, different bits: %d\n", x, y, compare_int32(x, y));

    return 0;
}