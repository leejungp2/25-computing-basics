#include <stdio.h>

void multiplication(void)
{
    int a, b;
    printf("Enter a number less than 1000 : ");
    scanf("%d", &a);
    printf("Enter a number less than 1000 : ");
    scanf("%d", &b);

    int ab1 = a * (b % 10);
    int ab2 = a * ((b / 10) % 10);
    int ab3 = a * (b / 100);
    printf("%d\n", ab1);
    printf("%d\n", ab2);
    printf("%d\n", ab3);
    printf("%d\n", ab3 * 100 + ab2 * 10 + ab3);
}

void rounding(void)
{
    float a;
    printf("Enter a non-negative decimal : ");
    scanf("%f", &a);
    printf("%d\n", (int)(a + 0.5));
}

void complex(void)
{
    float a, b, c, d;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("(%f%+fi)*(%f%+fi) = %f%+fi\n",
           a, b, c, d,
           (a * c - b * d), a * d + b * c);
}

int main(void)
{
    multiplication();
    rounding();
    complex();
}