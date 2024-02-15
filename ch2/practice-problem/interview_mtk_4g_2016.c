#include <stdio.h>

int main()
{
    unsigned long v1 = 0x00001111;
    unsigned long v2 = 0x00001202;
    unsigned long v;
    v = v1 & (~v2);
    printf("v1 & (~v2): 0x%lx\n", v);
    v = v | v2;
    printf("v | v2: 0x%lx\n", v);
    return 0;
}