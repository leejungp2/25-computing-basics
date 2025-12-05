#include <stdio.h>
int num1 = 1;

int main(void){
    printf("%d\n", num1);
    {
        int num2 = 10 + num1;
        printf("%d\n", num2);
        {
            int num3 = 100 + num2;
            printf("%d\n", num3);
        }
        printf("%d\n", num2);
    }
    printf("%d\n", num1);
    return 0;
}