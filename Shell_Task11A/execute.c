#include "shell.h"

void execute_commands(const char *commands)
{
    char *commands_copy = strdup(commands);
    char *args[MAX_ARGS];
    char *trimmed_command;
     int len;
    
    if (commands_copy == NULL)
    {
        perror("execute_commands: strdup");
        return;
    }

    char *token = _strtok(commands_copy, ";");
    while (token != NULL)
    {
        trimmed_command = token;
        while (*trimmed_command == ' ')
            trimmed_command++;
        len = strlen(trimmed_command);
        while (len > 0 && trimmed_command[len - 1] == ' ')
            trimmed_command[--len] = '\0';

        if (trimmed_command[0] != '\0')
        {
            tokenizeCommand(trimmed_command, args);

            if (strcmp(args[0], "exit") == 0)
                _handle_exit(args[0]);
            else if (strcmp(args[0], "setenv") == 0)
                _setenv(args[1], args[2], 0);
            else if (strcmp(args[0], "unsetenv") == 0)
                unsetenv(args[1]);
            else if (strcmp(args[0], "cd") == 0)
                _cd(args[1]);
            else
            {
                if (fork() == 0)
                {
                    execve(args[0], args);
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    wait(NULL);
                }
            }
        }
        token = _strtok(NULL, ";");
    }

    free(commands_copy);
}
