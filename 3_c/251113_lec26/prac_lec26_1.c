#include <stdio.h>
#include <stdbool.h>

// 중괄호 바깥에 선언된 게 global variable

int main(void){
    int intVar;
    printf("int size is %d\n", sizeof(intVar));

    char charVar;
    printf("char size is %d\n", sizeof(charVar));

    float floatVar;
    printf("float size is %d\n", sizeof(floatVar));
    
    double doubleVar;
    printf("double size is %d\n", sizeof(doubleVar));

    bool boolVar;
    printf("bool size is %d\n", sizeof(boolVar));
    // 이름과 data type이 binding이 되어버림
    // data type은 immutable, value는 mutable

    return 0;
}