#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

// Function declarations
void read_input(char* input);
void parse_input(char* input, char** args);

void read_input(char* input) {
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove newline character if present
    size_t input_len = strlen(input);
    if (input_len > 0 && input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
    }
}

void parse_input(char* input, char** args) {
    char* token;
    int arg_count = 0;

    token = strtok(input, " ");
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }

    args[arg_count] = NULL;
}
