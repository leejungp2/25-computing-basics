#include <stdio.h>
#include <stdbool.h>

int GlobalVar;

int main(void) {
    int x = 1;
    int y;
    int z;

    printf("x is %d, y is %d, and z is %d\n", x, y, z);

    y = x++;
    printf("x is %d, y is %d, and z is %d\n", x, y, z);

    z = ++y;
    printf("x is %d, y is %d, and z is %d\n", x, y, z);

    return 0;
}