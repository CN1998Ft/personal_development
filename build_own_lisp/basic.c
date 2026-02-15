#include <stdio.h>
#include <math.h>
// This file is the basic section of chapter 3.


// Define the add function.
int add_together(int x, int y) {
    int result = x + y;
    return result;
}

void hello_world(int n) {
    while (n > 0) {
        puts("\nHello World!\n");
        n -= 1;
    }
}


// Define the structure named point.
typedef struct {
    float x;
    float y;
} point;


int main(){
    int added = add_together(10, 18);
    printf("\nThe result of the added is %d\n", added);

    point p;
    p.x = 0.1f;
    p.y = 10.0f;
    float length = sqrt(p.x * p.x + p.y * p.y);
    printf("\nThe length of point is %f\n", length);
    length = 9;
    if (length > 10 && length < 100){
        puts("length is greater than 10 and less than 100");
    } else {
        puts("\nlength is less than or equal to 10 or greater than and equal to"
                "100\n");
    }

    // The while loop.
    int i = 10;
    while (i > 0) {
        puts("This is inside the while loop.");
        i -= 1;
    }

    // The for loop.
    for (int i = 0; i < 10; i++) {
        printf("This is inside the for loop, and iter: %d\n", i);
    }


    // The bonus marks:
    for (int i = 0; i < 5; i++) {
        puts("\nHello World!\n");
    }
    int z = 0;
    while (z < 5) {
        puts("\nHello World!\n");
        z += 1;
    }
    hello_world(5);
    // The basic types in c are:
    // int    float    double    char    bool   void
    return 0;
}
