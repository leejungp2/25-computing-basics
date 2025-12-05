#include <stdio.h>
#include <stdbool.h>

int test(void)
{
    for (int i = 2; i < 100; i++)
    {
        bool is_prime = true;
        for (int y = 2; y < i; y++)
        {
            if (i % y == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

int test2(void)
{
    int num;
    scanf("%d", &num);
    // num >= 2
    int divisor = 2;
    while (num > 1)
    {
        int count = 0;
        while (num % divisor == 0)
        {
            num /= divisor;
            count++;
        }
        if (count > 0)
        {
            printf("(%d,%d)", divisor, count);
        }
        divisor++;
    }
    return 0;
}

int fibo(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
    printf("%d\n", fibo(3));
    printf("%d\n", fibo(5));
}