#include <stdio.h>

// while
int main(void){
    int x = 0;

    while (x<10) {
        printf("%d\n", x);
        x++;
    }

    return 0;
}

//do-while
int main2(void){
    int x = 0;

    do{
        printf("%d\n", x);
        x++;
    } while(x < 10);

    return 0;
}