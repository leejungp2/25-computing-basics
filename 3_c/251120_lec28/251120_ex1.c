int sum_of_digits(int N) {
    int sum = 0;

    while (N > 0) {
        sum += N % 10; // 마지막 자리 더하기
        N /= 10; // 한 자리 줄이기
    }
    return sum;
}