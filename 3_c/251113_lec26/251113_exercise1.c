#include <stdio.h>
// Create a function that print the multiplication result for
int main(void){
    int a, b;
    printf("Enter a number less than 1000 :");
    scanf("%d", &a);
    printf("Enter a number less than 1000:");
    scanf("%d", &b);
    ///// write your code
    int result = a * b;   // 곱셈 수행
    printf("Result: %d\n", result);  // 출력

    return 0;

}

//교수님 코드
int main(void){
    int a = 123;
    int b = 456;
    // 123*6
    // 123*5
    // 123*4
    printf("%d\n", a*(b%10));
    printf("%d\n", a*((b/10)%10));
    printf("%d\n", a*(b%10));
    int a, b;
    printf("Enter a number less than 1000 :");
    scanf("%d", &a);
    printf("Enter a number less than 1000:");
    scanf("%d", &b);
    int result = a * b;   // 곱셈 수행
    printf("Result: %d\n", result);  // 출력

    return 0;

}