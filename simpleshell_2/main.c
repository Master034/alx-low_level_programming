#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while (1) {
        printf("simple_shell$ ");
        characters = getline(&command, &bufsize, stdin);

        if (characters == -1) {
            if (feof(stdin)) {
                printf("\n");  // Handle end of file condition (Ctrl+D)
                break;
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }

        if (characters > 0 && command[characters - 1] == '\n') {
            command[characters - 1] = '\0';  // Remove the trailing newline character
        }

        // Execute the command
        if (command[0] != '\0') {
            if (fork() == 0) {
                // Child process
                char *args[] = {command, NULL};
                execve(command, args, NULL);
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                wait(NULL);  // Wait for the child process to complete
            }
        }
    }

    free(command);
    return 0;
}
