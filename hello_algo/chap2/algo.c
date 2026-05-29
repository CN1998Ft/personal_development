#include <stdio.h>
void print_linebreaker(char *message){
    printf("%s\n", message);
}

int forLoop(int n){
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += i;
    }
    return res;
}

int whileLoop(int n){
    int res = 0;
    int i = 1;
    while (i <= n){
        res += i;
        i ++;
    }
    return res;
}

int main() {
    char message1[30] = "\n=== The for loop code. ====\n";
    // char* message1 = "\n=== The for loop code. ====\n";
    print_linebreaker(message1);
    int forloop = forLoop(10);
    printf("The result from forLoop function is: %d\n", forloop);
    return 0;
}
