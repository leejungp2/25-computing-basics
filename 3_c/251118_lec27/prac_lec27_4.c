#include <stdio.h>

// nested for loop
int main(void) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("%d\t", x*y);
        }
        printf("\n");
    }
    return 0;
}