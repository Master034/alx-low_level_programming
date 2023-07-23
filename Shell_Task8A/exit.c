#include "shell.h"

void _exit(char *command)
{
    char *arg = _strtok(NULL, " ");
    if (arg != NULL)
    {
        int status = atoi(arg);
        free(command);
        exit(status); 
    }
    else
    {
        free(command);
        exit(EXIT_SUCCESS); 
    }
}
