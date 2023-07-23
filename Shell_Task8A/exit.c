#include "shell.h"


void _exit(char *command) {
    // Check if there are arguments after "exit"
    char *arg = strtok(NULL, " ");
    if (arg != NULL)
    {
        // Convert the status argument to an integer
        int status = atoi(arg);
        free(command);
        exit(status); // Terminate the shell with the specified status
    }
    else
    {
        free(command);
        exit(EXIT_SUCCESS); // Terminate the shell without a status argument
    }
}
