
// 교수님 풀이
int p3 = 1;
int sum = 0; // 여기에 누적


#include <stdio.h>

// GPT?
int f(int n){
    int sum = 0;
    int p3 = 1;

    while(n > 0){
        if(n & 1)
            sum += p3;
        p3 *= 3;
        n >>= 1;
    }
    return sum;
}

// main (테스트용)

int main(void) {
    for (int i = 1; i <= 10; i++) {
        printf("F(%d) = %lld\n", i, power_of3_sequence(i));
    }
    return 0;
}