#include <stdio.h>

int main() {
  printf("\nHello from chapter3.\n");

  printf("\nThe basic data types.\n");
  printf("The size of the short in c is: %zu bytes.\n", sizeof(short));
  printf("The size of the int in c is: %zu bytes.\n", sizeof(int));
  printf("The size of the long in c is: %zu bytes.\n", sizeof(long));
  printf("The size of the long long in c is: %zu bytes.\n", sizeof(long long));
  printf("The size of the char in c is: %zu bytes.\n", sizeof(char));
  printf("The size of the float in c is: %zu bytes.\n", sizeof(float));
  printf("The size of the double in c is: %zu bytes.\n", sizeof(double));

  printf("\nThe number encoding:\n");
  printf("The sign magnitued, 0000 0001 = 1 and 1000 0001 = -1.\n");
  printf("The left most bit to represent the positive or negative.\n");

  printf("\nThe 1's complement, 0000 0001 = 1 and 1111 1110 = -1.\n");
  printf("The negative value is simple invert all the bit.\n");

  printf("\nThe 2's complement, 0000 0001 = 1 and 1111 1111 = -1.\n");
  printf("The negative value for 2's complement is same as 1'st complement.\n");
  printf("But add 1 after inverted all the bits.\n");

  printf("\nThe sign magnitude and 1's complement introduces two zero representations.\n");
  printf("A positive and negative zero, 1000 0000 and (0000 0000, 1111 1111).\n");
  printf("This ambiguity can cause unexpected errors and handling this will cause extra time complexity.\n");
  printf("Thus, the 2's complement is more common in modern computing.\n");
  printf("The 2's complement will have zero as 1111 1111 + 1 = 1 0000 0000.\n");
  printf("As this example only holds 8 bits, the 9th bit will be overflowed.\n");

  printf("\nThe floating number according to the IEEE 754 standard, a 32-bit float.");
  printf("\nCan be represented as: b31b30...b3b2b1b0\n");
  printf("Where b31 is the sign bit for indicating the positive or negative.\n");
  printf("Also, watch Casey Muratori's handmade hero for floating number explanation.\n");

  return 0;
}
