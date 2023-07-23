#include "shell.h"

void execute_commands(const char *commands)
{
    char *commands_copy = strdup(commands);
    char *args[MAX_ARGS];
    char *trimmed_command;
    char *semicolon_token;
    char *token = NULL;
     int arg_count = 1, status;
    char *command;
    pid_t pid;

    if (commands_copy == NULL)
    {
        perror("execute_commands: strdup");
        return;
    }

    semicolon_token = strtok(commands_copy, ";");
    while (semicolon_token != NULL)
    {
        trimmed_command = semicolon_token;
        while (*trimmed_command == ' ')
            trimmed_command++;
        int len = strlen(trimmed_command);
        while (len > 0 && trimmed_command[len - 1] == ' ')
            trimmed_command[--len] = '\0';

        if (trimmed_command[0] != '\0')
        {
            char *token = _strtok(trimmed_command, " ");
            command = token;
            token = _strtok(NULL, " ");
            while (*command == ' ')
                command++;
            int len = strlen(command);
            while (len > 0 && command[len - 1] == ' ')
                command[--len] = '\0';

            if (command[0] != '\0')
            {
                char *args[MAX_ARGS];
                args[0] = command;
                int arg_count = 1;
                while (token != NULL)
                {
                    while (*token == ' ')
                        token++;
                    len = strlen(token);
                    while (len > 0 && token[len - 1] == ' ')
                        token[--len] = '\0';

                    if (token[0] != '\0')
                    {
                        args[arg_count++] = token;
                        if (arg_count >= MAX_ARGS - 1)
                            break;
                    }

                    token = _strtok(NULL, " ");
                }

                args[arg_count] = NULL;
                pid = fork();
                if (pid == -1)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
                    execve(args[0], args, environ);
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    waitpid(pid, &status, 0);
                }
            }
        }

        semicolon_token = _strtok(NULL, ";");
    }

    free(commands_copy);
}
