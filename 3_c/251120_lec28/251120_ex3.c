//교수님 풀이
//RECURSIVE
//if (n == 1):

//else: return 2f(n-1)+1

// GPT
#include <stdio.h>

int hanoi_count(int n) {
    if (n == 1)
        return 1;
    return 2 * hanoi_count(n - 1) + 1;
}

int main(void) {
    int n = 5;
    printf("Number of moves for %d disks: %d\n", n, hanoi_count(n));
    return 0;
}