// Q. Multiply Two Complex Numbers
// Read two complex numbers (a+bi) and (c+di) and print the result.
// Rules: Use the %+ flag in printf to show signs without branching.

# include <stdio.h>

int main(void){
    float a, b, c, d;

    printf("Enter a b c d: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    // TODO
    int real = a*c - b*d;
    int img = a*d + b*c;
    
    printf("(%d%+%di)*(%d%+di)=%+d+di\n",
        a, b, c, d, real, img
    );
    //printf("Result: %+f %+fi\n", real, complex);

}