#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_linebreaker(char *message)
{
    printf("%s\n", message);
}

int forLoop(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += i;
    }
    return res;
}

int whileLoop(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
    }
    return res;
}

int whileLoopII(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
        i *= 2;
    }
    return res;
}

char *nestedForLoop(int n)
{
    int size = n * n * 26 + 1;
    char *res = malloc(size * sizeof(char));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            char tmp[26];
            snprintf(tmp, sizeof(tmp), "(%d, %d), ", i, j);
            strncat(res, tmp, size - strlen(res) - 1);
        }
    }
    return res;
}

int recur(int n)
{
    // Recursion usually consumes more memory and take longer than iteration.
    // This is because the call stack, each iteration will allocate memory
    //  for newly invoked function to store data and local variable. And they
    //  will not be release until the function stops. And no function overhead.
    if (n == 1)
    {
        return 1;
    }
    int res = recur(n - 1);
    return n + res;
}

int tailRecur(int n, int res)
{
    // However, when the recursion happens at the end of the function, one step
    // before the return. The compiler will optimise this Tail Recursion. So
    //  the Space complexity will be similiar to the iteration.
    if (n == 0)
    {
        return res;
    }
    return tailRecur(n - 1, res + n);
}

int fib(int n)
{
    // When dealing with algorithmic problems like fibonacci sequence, like
    // "divide and conquer" style is more intuitive to solve with recursion.
    // fib = f(n - 1) + f(n - 2)
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    int res = fib(n - 1) + fib(n - 2);
    return res;
}

int myfib(int n)
{
    // Not performance enhanced, and make debugging difficult too. Use the first
    // one, compiler will deal with this, it does not save neither time nor
    // space.
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int forLoopRecur(int n)
{
    int stack[1000];
    int top = -1;
    int res = 0;
    for (int i = n; i > 0; i--)
    {
        stack[1 + top++] = i;
    }

    while (top >= 0)
    {
        res += stack[top--];
    }
    return res;
}

int main()
{
    char message1[30] = "\n=== The for loop code. ====\n";
    // char* message1 = "\n=== The for loop code. ====\n";
    print_linebreaker(message1);
    int forloop = forLoop(10);
    printf("The result from forLoop function is: %d\n", forloop);
    int whileloop = whileLoop(10);
    printf("The result from whileLoop funciton is: %d\n", whileloop);
    int whileloopii = whileLoopII(10);
    printf("The result from whileLoopII funciton is: %d\n", whileloopii);
    char *nestedforloop = nestedForLoop(10);
    printf("The result from nestedForLoop function is: %s\n", nestedforloop);
    // Decided to comment this out, according to mz zozin, the os should be
    // smart enough to free the memory after use.
    // free(nestedforloop);
    int recurResult = recur(10);
    printf("The result from recur function is: %d\n", recurResult);
    int tailrecur = tailRecur(10, tailrecur);
    printf("The result from tailRecur function is: %d\n", tailrecur);
    int fibonacci = fib(10);
    printf("The result from fib function is: %d\n", fibonacci);
    int myfibonacci = fib(2);
    printf("The result from myfib function is: %d\n", myfibonacci);
    // The recursion break the big problem into smaller tasks, in a "divide and
    // conquer" strategy.
    int simulateRecur = forLoopRecur(10);
    printf("The result from forLoopRecur function is %d\n", simulateRecur);
    return 0;
}
