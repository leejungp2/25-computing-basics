#include <stdio.h>

void reverse_arr(int x*, int size){ //x[] 대신 x* 해도 pointer로 인식
    int *left = &x[0];
    int *right = &x[size-1];

    while (left < right){
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

}

int main(void)
{
    int x[]= {3, 1, 4, 6, 5, 9 ,2};
    reverse_arr(x, 7);
    for (int i = 0; i <7; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
}

// ppt에 나와있는 코드가 뭔지 모르겠음 (다른 ppt 확인)