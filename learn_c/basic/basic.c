#include <stdio.h>

int main() {
    printf("Hellow World!\nI'm Learning C now!\nAnd this is Awesome!\n");
    printf("Below is the pyramid\n");
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");

    int myValue = 15;
    int sum = myValue + 25;
    float floatValue = 15.0;
    char myChar = 'F';
    printf("My value is the %d and float value is %f. The character is: %c\n",
           myValue, floatValue, myChar);
    printf("The sum of the integer is: %d.\n", sum);

    // Swap value method 1
    int temp;
    temp = myValue;
    myValue = sum;
    sum = temp;
    printf("The swapped value of myValue: %d, and swapped value of sum: %d.\n",
           myValue, sum);

    // swap value method 2 using xor
    myValue = myValue ^ sum;
    sum = myValue ^ sum;
    myValue = myValue ^ sum;
    printf("The swapped back value of myValue: %d, and swapped back value of "
           "sum: %d.\n",
           myValue, sum);

    int x, y, z;
    x = y = z = 50;
    printf("x is %d, y is %d, z is %d.\n", x, y, z);

    int x1 = 50, y1 = 50, z1 = 25;
    printf("x1 is %d, y1 is %d, z1 is %d.\n", x1, y1, z1);

    int studentID = 15;
    int studentAge = 23;
    float studentFee = 75.25;
    char studentGrade = 'B';

    puts("");
    printf("Student ID: %d\n", studentID);
    printf("Student Age: %d\n", studentAge);
    printf("Student Fee: %f\n", studentFee);
    printf("Student Grade: %c\n", studentGrade);

    int length = 4;
    int width = 6;
    int area;
    area = length * width;
    puts("");
    printf("The area of the rectangle is %d.\n", area);
    return 0;
}
