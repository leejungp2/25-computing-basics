#include <stdio.h>

void reversarr(int x[], int size)
{
    int *left = x;
    int *right = x + (size - 1);

    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int reverse(int x)
{
    int y = 0;
    while (x > 0)
    {
        y = 10 * y + (x % 10);
        x /= 10;
    }
    return y;
}

void reverswap(int *a, int *b)
{
    int temp = reverse(*a);
    *a = reverse(*b);
    *b = temp;
}

void selection_sort(int x[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        int smallest_at = i;
        for (int j = i + 1; j < size; j++)
        {
            if (x[j] < x[smallest_at])
            {
                smallest_at = j;
            }
        }
        temp = x[i];
        x[i] = x[smallest_at];
        x[smallest_at] = temp;
    }
}

int main(void)
{
    int a = 1234, b = 6789;
    int x[] = {3, 1, 4, 6, 5, 9, 2};
    reverswap(&a, &b);
    printf("%d, %d\n", a, b);

    reversarr(x, 7);
    // selection_sort(x, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}