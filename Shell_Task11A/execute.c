void execute_commands(const char *commands)
{
    char *commands_copy = strdup(commands);
    if (commands_copy == NULL)
    {
        perror("execute_commands: strdup");
        return;
    }

    char *token = strtok(commands_copy, ";");
    while (token != NULL)
    {
        char *trimmed_command = token;
        while (*trimmed_command == ' ')
            trimmed_command++;
        int len = strlen(trimmed_command);
        while (len > 0 && trimmed_command[len - 1] == ' ')
            trimmed_command[--len] = '\0';

        if (trimmed_command[0] != '\0')
        {
            // Tokenize and execute the trimmed_command here.
            char *args[MAX_ARGS];
            tokenizeCommand(trimmed_command, args);

            if (strcmp(args[0], "exit") == 0)
                _handle_exit(args[0]);
            else if (strcmp(args[0], "setenv") == 0)
                _setenv(args[1], args[2], 0);
            else if (strcmp(args[0], "unsetenv") == 0)
                unsetenv(args[1]);
            else if (strcmp(args[0], "cd") == 0)
                cd(args[1]);
            else
            {
                // Fork and execute external commands
                if (fork() == 0)
                {
                    execvp(args[0], args);
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    wait(NULL);
                }
            }
        }
        token = strtok(NULL, ";");
    }

    free(commands_copy);
}
