#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

// Function declarations
void read_input(char* input);
void parse_input(char* input, char** args);
void execute_command(char** args);

int main() {
    char input[MAX_INPUT_SIZE];
    char* args[MAX_ARGS];

    while (1) {
        printf("shell> ");
        fflush(stdout);

        read_input(input);
        parse_input(input, args);
        execute_command(args);
    }

    return 0;
}
