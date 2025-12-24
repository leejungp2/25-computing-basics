#include <stdio.h>

void selection_sort(int L[], int size){

    for (int i = 0; i < size; i++)
    {
            int smallest = i;
            for (int j = i; j<size; i++)
            {
                if(L[j]<L[smallest])
                {
                    smallest = j;
                }
            }
            int temp = L[i];
            L[i] = L[smallest];
            // 뭔가 한 줄 놓침

    }
    

}

// 슬라이드에서 void reverse, void swap의 역할?

int main(void)
{
    int x[]= {3, 1, 4, 6, 5, 9 ,2};
    selection_sort(x, 7);
    for (int i = 0; i <7; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
}
