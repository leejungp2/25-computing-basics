#include <stdio.h>

int main(void) {
    for (int x = 0; x < 10; x++) {
        if (x == 5) {
            continue;
        }
        printf("%d\n", x);
    }

    return 0;
}