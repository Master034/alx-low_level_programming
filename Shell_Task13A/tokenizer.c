#include "shell.h"

void tokenizeCommand(char *command, char **args)
{
    char *comment_ptr = strchr(command, '#');
    
     if (comment_ptr != NULL) {
        *comment_ptr = '\0';
    }
    int arg_count = 0;
    char *token = strtok(command, " ");
    
    while (token != NULL && arg_count < MAX_ARGS - 1)
    {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;
}
