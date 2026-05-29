#include <stdio.h>

void test_understanding(int *input, int multiplier){
    *input = *input * multiplier;
}

int main() {
    int integer = 10;
    int *pointer = &integer;
    printf("The value of integer is: %d.\n", integer);
    test_understanding(&integer, 3);
    printf("The de-referenced pointer is: %d.\n", *pointer);
    if (integer == *pointer){
        puts("\nThe *pointer and integer are the same thing.");
        puts("They are the value saved at the memory address.\n");
    }

    /* The value of integer is the integer assigned.
    Therefore, the pointer should take the &integer (the address of the integer)

    */
    printf("The pointer is: %p.\n", pointer);
    printf("The &integer is: %p.\n", &integer);
    if (pointer == &integer){
        puts("\nThe pointer and &integer are the same thing.");
        puts("They are the memory address.\n");
    }
    printf("The &pointer is: %p. The pointer's address.\n", &pointer);
    printf("Therefore, the function will need to take a *input (the address of ");
    printf("the input value) %p. ", pointer);
    printf("Therefore, inside the function defination, the operation is ");
    printf("dealing with the dereferenced pointer (the value stored at the ");
    printf("memory address. %d. ", *pointer);
    printf("So, when using the function, we need to pass in the address of ");
    printf("the value. Hence, &input. %p.\n", &integer);
    return 0;
}
