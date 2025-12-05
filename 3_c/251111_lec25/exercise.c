# include <stdio.h>

#define STOP 0

int main(void){

    int counter;
    int startPoint; // 변수 선언 먼저

    printf("====Countdown Program\n");
    printf("Pls input pos-int :");
    scanf("%d", &startPoint);

    for(counter=startPoint; counter >= STOP; counter--){
        // for loop 문법 다름
        // K, A, 10
        printf("%c\n", 'A'+counter);
    }

    return 0;

}