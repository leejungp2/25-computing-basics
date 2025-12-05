#include <stdio.h>
#include <stdlib.h>

// Implement a structure Point
typedef struct point {
    float x;
    float y;
} Point;
// Implement a structure Rectangle
typedef struct rectangle {
    Point a;
    Point b;
} Rectangle;


float width(Rectangle rect){
    float result=0;
    ///here///
    result = rect.b.x - rect.a.x;
    //////////
    return result;
}

float height(Rectangle rect){
    float result=0;
    ///here///  
    result = rect.a.y - rect.b.y;
    //////////
    return result;
}

float area(Rectangle rect){
    float result=0;
    ///here///
    result = width(rect) * height(rect);
    //////////
    return result;
}

Point centroid(Rectangle rect){
    Point centroid;
    centroid.x = (rect.a.x + rect.b.x) / 2; ////here
    centroid.y = (rect.a.y + rect.b.y) / 2; ////here
    return centroid;
}



/* Do not modify below */
int main(int argc, char *argv[]){
    if((argc == 2) || (argc == 4) || argc > 5) {
        printf("Invalid Input!\n");
    }

    else {
        Point a,b;
        if(argc == 5){
            a.x = atof(argv[1]);
            a.y = atof(argv[2]);
            b.x = atof(argv[3]);
            b.y = atof(argv[4]);
        } 
        else if (argc==3) {
            a.x = atof(argv[1]);
            a.y = atof(argv[2]);
            printf("Enter a bottom-right point : ");
            scanf("%f %f",&b.x, &b.y);
        } 
        else if (argc==1) {
            printf("Enter a top-left point : ");
            scanf("%f %f",&a.x, &a.y);
            printf("Enter a bottom-right point : ");
            scanf("%f %f",&b.x, &b.y);
        }
        if ((a.x > b.x) || (a.y < b.y)) {
            printf("Invalid Input!\n");
        } else {
            Rectangle rect;
            rect.a = a;
            rect.b = b;
            printf("Bounding Box : (%.1f, %.1f, %.1f, %.1f)\n", centroid(rect).x, centroid(rect).y, width(rect), height(rect));
            printf("Area : %.1f\n", area(rect));
        }
    }


    return 0;
}

/*
Compile command
---------------
gcc 2_Bbox.c -o 2_Bbox

Test cases
----------
./2_Bbox 10 40 55 10
Bounding Box : (32.5, 25.0, 45.0, 30.0)
Area : 1350.0

./2_Bbox 10 40
Enter a bottom-right point : 55 10
Bounding Box : (32.5, 25.0, 45.0, 30.0)
Area : 1350.0

./2_Bbox
Enter a top-left point : 10 40
Enter a bottom-right point : 55 10
Bounding Box : (32.5, 25.0, 45.0, 30.0)
Area : 1350.0

./2_Bbox 10 40 50 50
Invalid Input!
*/