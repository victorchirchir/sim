#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function declarations
void execute_command(char** args);

void execute_command(char** args) {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Command execution failed.\n");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}
