#include <stdio.h>
#include <stdlib.h>
#define MEMS 7

// Implement a structure Person
typedef struct person
{
    int id;
    int age;
    char name[10];
    int grade;
    char team;
}
// Implement a function that indicate the team each person belongs to
// The function name should be 'indicateTeam'
float indicateTeam(Person* members, int num_men) { //쓰지 않더라도 array 길이 넣어줌 num_men
    for (int i=0; i<num_men; i++;){
        sum += members[i].age;
    }
    float average = sum / num_men;
    for (int = 0; i<num_men; i++);
    /// ?? 
}

/* Do not modify below */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <test_case_number>\n", argv[0]);
        return 1;
    }

    int testCase = atoi(argv[1]);
    if (testCase < 1 || testCase > 4) {
        printf("Invalid test case number. Please provide a number between 1 and 4.\n");
        return 1;
    }

    Person members[MEMS];
    switch (testCase) {
        case 1:
            // Test case 1
            printf("Running Test Case 1:\n");
            Person case1[MEMS] = {
                {1, 22, "BH", 2, 'N'},
                {2, 20, "YP", 1, 'N'},
                {4, 25, "KS", 3, 'N'},
                {3, 22, "SS", 3, 'N'},
                {5, 23, "JG", 2, 'N'},
                {6, 22, "JD", 1, 'N'},
                {7, 21, "HJ", 1, 'N'}
            };
            for (int i = 0; i < MEMS; i++) members[i] = case1[i];
            break;

        case 2:
            // Test case 2
            printf("Running Test Case 2:\n");
            Person case2[MEMS] = {
                {1, 18, "AA", 1, 'N'},
                {2, 19, "BB", 2, 'N'},
                {3, 20, "CC", 3, 'N'},
                {4, 21, "DD", 4, 'N'},
                {5, 22, "EE", 1, 'N'},
                {6, 23, "FF", 2, 'N'},
                {7, 24, "GG", 3, 'N'}
            };
            for (int i = 0; i < MEMS; i++) members[i] = case2[i];
            break;

        case 3:
            // Test case 3
            printf("Running Test Case 3:\n");
            Person case3[MEMS] = {
                {1, 30, "X1", 4, 'N'},
                {2, 32, "X2", 3, 'N'},
                {3, 28, "X3", 2, 'N'},
                {4, 35, "X4", 5, 'N'},
                {5, 27, "X5", 1, 'N'},
                {6, 26, "X6", 2, 'N'},
                {7, 33, "X7", 4, 'N'}
            };
            for (int i = 0; i < MEMS; i++) members[i] = case3[i];
            break;

        case 4:
            // Test case 4
            printf("Running Test Case 4:\n");
            Person case4[MEMS] = {
                {1, 15, "Z1", 1, 'N'},
                {2, 14, "Z2", 2, 'N'},
                {3, 16, "Z3", 3, 'N'},
                {4, 17, "Z4", 4, 'N'},
                {5, 13, "Z5", 1, 'N'},
                {6, 12, "Z6", 2, 'N'},
                {7, 18, "Z7", 3, 'N'}
            };
            for (int i = 0; i < MEMS; i++) members[i] = case4[i];
            break;
    }

    float mean = indicateTeam(members, MEMS);
    printf("Mean age: %.2f\n", mean);

    for (int i = 0; i < MEMS; i++) {
        printf("Name: %s, Age: %d, Team: %c\n", members[i].name, members[i].age, members[i].team);
    }

    return 0;
}

/*
Compile command
---------------
gcc 3_obyb.c -o 3_obyb

Test cases
----------
./3_obyb 1
Running Test Case 1:
Mean age: 22.14
Name: BH, Age: 22, Team: Y
Name: YP, Age: 20, Team: Y
Name: KS, Age: 25, Team: O
Name: SS, Age: 22, Team: Y
Name: JG, Age: 23, Team: O
Name: JD, Age: 22, Team: Y
Name: HJ, Age: 21, Team: Y

(We provided test cases 1 - 4)
*/