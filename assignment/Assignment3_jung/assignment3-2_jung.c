#include <stdio.h>


int getStepsRecursive(int n);
int getMaxValue(int n);
int findLongestInRange(int limit); 

int main(void) {
    //DO NOT MODIFY THE MAIN FUNCTION
    int inputNum;

    printf("=== Collatz Conjecture Analyzer ===\n");

    while (1) {
        printf("\nEnter a positive integer to start, 0 to exit: ");
        scanf("%d", &inputNum);

        if (inputNum == 0) {
            printf("Program Ended.\n");
            break;
        }
        if (inputNum < 1) {
            printf("Please enter a positive integer.\n");
            continue;
        }

        
        printf("\n--- Analysis for Number %d ---\n", inputNum);
        int steps = getStepsRecursive(inputNum);
        int maxVal = getMaxValue(inputNum);
        printf("[Task 1] Steps to reach 1: %d\n", steps);
        printf("[Task 2] Max value reached: %d\n", maxVal);

        
        printf("\n--- Analysis for Range 1 to %d ---\n", inputNum);
        int MaxLongestRange=findLongestInRange(inputNum);
        printf("[Task 3] Max value reached with the longest steps is: %d\n", MaxLongestRange);
    }

    return 0;
}


int getStepsRecursive(int n) {
    if (n == 1) {
        return 0;
    }
    if (n % 2 == 0) {
        return 1 + getStepsRecursive(n / 2);
    } else {
        return 1 + getStepsRecursive(3 * n + 1);
    }
}


int getMaxValue(int n) {
    int max = n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        if (n > max) {
            max = n;
        }
    }
    return max;
}


int findLongestInRange(int limit) {
    int bestSteps = -1;
    int bestNum = 1;
    int bestMax = 1;

    for (int i = 1; i <= limit; i++) {
        int steps = getStepsRecursive(i);
        int maxVal = getMaxValue(i);

        // 1) 스텝 수가 기존 최고보다 크면 무조건 갱신
        if (steps > bestSteps) {
            bestSteps = steps;
            bestNum = i;
            bestMax = maxVal;
        }
        // 2) 스텝 수가 같으면 숫자가 더 큰 것 선택
        else if (steps == bestSteps && i > bestNum) {
            bestNum = i;
            bestMax = maxVal;
        }
    }

    return bestMax;
}