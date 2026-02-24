#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function as windows automatically does what it does.
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char* unused) {}
#elif __linux__
#include <editline/readline.h>
#endif
// #include <editline/history.h>


int main(int argc, char** argv) {
    puts("Lispy Version 0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while (1){
        char* input = readline("lisp> ");

        add_history(input);
        printf("No you are a %s\n", input);
        free(input);
    }
    return 0;
}
/* 
The #ifndef is: if not defined
#define is: define some macros
The linux equivalent of _WIN32 is __linux__ and __apple__ for macos.
*/
