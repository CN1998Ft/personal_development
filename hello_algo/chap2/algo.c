#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printf_info_integer(const char *function_name, int integer){
    printf("The result from %s function is: %d.\n", function_name, integer);
}

void printf_info_string(const char *function_name, const char *strings){
    printf("The result from %s function is: %s.\n", function_name, strings);
}

// The printf_info will call different function based on the type of second
// input of the macros function.
// I love macros in C.
#define printf_info(function_name, value) _Generic((value), \
            int: printf_info_integer,  \
            char *: printf_info_string \
            )(function_name, value)


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

void iteration_and_recursion(){
    printf("\n========== The iteration and recursion sub-chapter. ==========\n");
    char message1[30] = "\n=== The for loop code. ====\n";
    print_linebreaker(message1);
    int forloop = forLoop(10);
    // printf("The result from forLoop function is: %d\n", forloop);
    printf_info("forLoop", forloop);
    int whileloop = whileLoop(10);
    // printf("The result from whileLoop funciton is: %d\n", whileloop);
    printf_info("whileLoop", whileloop);
    int whileloopii = whileLoopII(10);
    // printf("The result from whileLoopII funciton is: %d\n", whileloopii);
    printf_info("whileLoopII", whileloopii);
    char *nestedforloop = nestedForLoop(10);
    // printf("The result from nestedForLoop function is: %s\n", nestedforloop);
    printf_info("nestedForLoop", nestedforloop);

    // Decided to comment this out, according to mz zozin, the os should be
    // smart enough to free the memory after use.
    // free(nestedforloop);
    int recurResult = recur(10);
    // printf("The result from recur function is: %d\n", recurResult);
    printf_info("recur", recurResult);
    int tailrecur = 0;
    tailrecur = tailRecur(10, tailrecur);
    // printf("The result from tailRecur function is: %d\n", tailrecur);
    printf_info("tailRecur", tailrecur);
    int fibonacci = fib(10);
    printf("The result from fib function is: %d\n", fibonacci);
    printf_info("fib", fibonacci);
    int myfibonacci = myfib(10);
    // printf("The result from myfib function is: %d\n", myfibonacci);
    printf("\nmyfib does not provide any optimisation, the compiler auto make ");
    printf("the recursion one step before return optimised. Thus, my fib \n");
    printf("only make debug more difficult. Use fib for recursion style.\n\n");
    printf_info("myfib", myfibonacci);
    // The recursion break the big problem into smaller tasks, in a "divide and
    // conquer" strategy.
    int simulateRecur = forLoopRecur(10);
    // printf("The result from forLoopRecur function is %d\n", simulateRecur);
    printf_info("forLoopRecur", simulateRecur);
    printf("\n========== The iteration and recursion sub-chapter. ==========\n");
}

void algorithm(int n){
    // Simulate the running time of a program.
    // In reality, not practical to calculate the runtime speed, and different
    // operating systems and platforms will have speed even with the same code.
    // Like neovim runs extremely slow comparing to other Posix compliant OS.
    int a = 2;
    a = a + 1;
    a = a * 2;
    for (int i = 0; i < n; i++){
        printf("%d", 0);
    }
}

void algorithm_A(int n){
    printf("%d", 0);
}

void algorithm_B(int n){
    for (int i = 0; i < n; i++){
        printf("%d", 0);
    }
}

void algorithm_C(int n){
    for (int i = 0; i < 1000; i++){
        printf("%d", 0);
    }
}

void time_growth(){
    algorithm_A(10);
    printf("\n");
    algorithm_B(10);
    printf("\n");
    algorithm_C(10);
    printf("\n");
}

int linear(int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        count++ ;
    }
    return count;
}

int arrayTraversal(int *nums, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        count++;
    }
    return count;
}

int quadratic(int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            count++;
        }
    }
    return count;
}

int exponential(int n){
    int count = 0;
    int bas = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < bas; j++){
            count++;
        }
        bas *= 2;
    }
    return count;
}

int expRecur(int n){
    if (n == 1){
        return 1;
    }
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

int logarithmic(int n){
    int count = 0;
    while (n > 1){
        n /= 2;
        count++;
    }
    return count;
}

int logRecur(int n){
    if (n <= 1){
        return 0;
    }
    return logRecur(n / 2) + 1;
}

int linearLogRecur(int n){
    if (n <= 1){
        return 1;
    }
    int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
    for (int i = 0; i < n; i++){
        count++;
    }
    return count;
}

int factorialRecur(int n){
    if (n == 0){
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        count += factorialRecur(n - 1);
    }
    return count;
}


int *randomNumbers(int n){
    int *nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        nums[i] = i + 1;
    }
    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return nums;
}

void time_complexity(){
    printf("\n========== The time complexity sub-chapter. ==========\n");

    algorithm(10);
    printf("\n");
    time_growth();

    int linearResult = linear(10);
    printf_info("linear", linearResult);

    int quadraticResult = quadratic(10);
    printf_info("quadratic", quadraticResult);

    int exponentialResult = exponential(10);
    printf_info("exponential", exponentialResult);

    int expRecurResult = expRecur(10);
    printf_info("expRecur", expRecurResult);

    int logarithmicResult = logarithmic(10);
    printf_info("logarithmic", logarithmicResult);

    int logRecurResult = logRecur(10);
    printf_info("logRecur", logRecurResult);

    // int linearLogRecurResult = linearLogRecur(10);
    // printf_info("linearLogRecur", linearLogRecurResult);
    printf_info("linearLogRecur", linearLogRecur(10));

    printf_info("factorialRecur", factorialRecur(10));


    printf("\n========== The time complexity sub-chapter. ==========\n");
    printf("\n");
}

int main()
{
    iteration_and_recursion();

    time_complexity();

    return 0;
}
