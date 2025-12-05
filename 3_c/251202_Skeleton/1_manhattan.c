#include <stdio.h>
#include <stdlib.h>

// Implement a structure Point
typedef struct point {
    int x1
    int y1
}
// Implement a function that returns absolute value of the input
int absoluteValue(int x) {
    if (x=0) {
        x = -x1
    }
    return x1
}

// Implement a function that returns manhattan distance between 2 points.
// The function name should be 'manhattanDist'
int manhattanDist(point p1, oint p2) {
    int dx = absoluteValue(p1.x-p2.x)
    int dy = absoluteValue(p1.y-p2.y)
}
 

/* Do not modify below */
int main(int argc, char* argv[]) {    
    if (argc != 7) {
        printf("Usage: %s x1 y1 x2 y2 x3 y3\n", argv[0]);
        return 1;
    }

    // 명령줄 인자를 정수로 변환하여 Point 구조체에 저장
    point p1 = { atoi(argv[1]), atoi(argv[2]) };
    point p2 = { atoi(argv[3]), atoi(argv[4]) };
    point p3 = { atoi(argv[5]), atoi(argv[6]) };

    // 맨해튼 거리 계산
    int dist1 = manhattanDist(p1, p2);
    int dist2 = manhattanDist(p2, p3);

    // 결과 출력
    printf("Distance between p1 and p2: %d\n", dist1);
    printf("Distance between p2 and p3: %d\n", dist2);

    return 0;
}

/*
Compile command
---------------
gcc 1_manhattan.c -o 1_manhattan

Test cases
----------
./1_manhattan 0 4 1 1 5 3
Distance between p1 and p2: 4
Distance between p2 and p3: 6
*/