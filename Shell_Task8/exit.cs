#include "shell.h"

/**
 * _exit-Checks exit status
 * @args:Array of arguments
 * Return:Nothing
 */
void _exit(char *command, char **args) {
    int exit_status = 0;
    int i = 0;

    if (args[1] != NULL)
        exit_status = atoi(args[1]);
    free(command);
    for (i ; args[i] != NULL; i++)
        free(args[i]);
    exit(exit_status);
}
