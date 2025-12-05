# include <stdio.h>
// functions in c - grammar
// factorial 함수

int Factorial(int n); 
// c에서는 뒤에 함수에 대한 definition 전체는 필요 없음. 다만, 앞줄은 미리 적어놔야함.

int main(void) { // return 값이 없는 함수를 만들려면 안에 void를 넣어야 함.
    int number;
    int answer;

    printf("Input a number: ");
    scanf("%d", &number);

    answer = Factorial(number); // 함수 정의 된 거 보고, 특정 datatype 넣어야 오작동 안함
    printf("The factorial of %d is %d\n", number, answer);

    return 0;
}

int Factorial(int n) { // 1. return datatype 2. 함수 이름 (3. input datatype parameter)
    // 이 안 애들은 다 local variable
    int result = 1;
    for (int i=1; i <= n; i++){
        result *= i;
    }
    return result;
}