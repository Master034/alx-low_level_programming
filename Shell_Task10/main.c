#include "shell.h"

/**
 * handle_exit-Checks exit status
 * @args:Array of arguments
 * Return:Nothing
 */
void handle_exit(char *command, char **args)
{
    int exit_status = 0;
    int i;

    if (args[1] != NULL)
        exit_status = atoi(args[1]);
    free(command);
    for (i = 0 ; args[i] != NULL; i++)
        free(args[i]);
    exit(exit_status);
}

int handle_setenv_command(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        write(2, "Usage: setenv VARIABLE VALUE\n", 28);
        return -1;
    }

    if (setenv(args[1], args[2], 1) != 0) {
        write(2, "setenv: Unable to set environment variable\n", 43);
        return -1;
    }

    return 0;
}

int handle_unsetenv_command(char **args) {
    if (args[1] == NULL) {
        write(2, "Usage: unsetenv VARIABLE\n", 25);
        return -1;
    }

    if (unsetenv(args[1]) != 0) {
        write(2, "unsetenv: Unable to unset environment variable\n", 47);
        return -1;
    }
    return 0;
}

int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *path_env = getenv("PATH");
    char *path_token = _strtok(path_env, ":");
    char path_command[BUFFER_SIZE];

    while (1)
    {
        printf("simple_shell$ ");
        characters = _getline(&command, &bufsize, stdin);
        
        if (characters == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }
        if (characters > 0 && command[characters - 1] == '\n')
            command[characters - 1] = '\0';
        else if (strcmp(command, "env") == 0)
            print_environment();
        if (command[0] != '\0')
        {
            char *args[MAX_ARGS];
            
            tokenizeCommand(command, args);
            if (strcmp(args[0], "exit") == 0)
                handle_exit(command, args);
            else if (strcmp(args[0], "setenv") == 0)
                handle_setenv_command(args);
            else if (strcmp(args[0], "unsetenv") == 0)
                handle_unsetenv_command(args);
            else if (strcmp(args[0], "cd") == 0)
                handle_cd_command(args);
            if (fork() == 0)
            {
                execve(args[0], args, NULL);
                while (path_token != NULL) {
                    snprintf(path_command, BUFFER_SIZE, "%s/%s", path_token, args[0]);
                    execve(path_command, args, environ);
                    path_token = _strtok(NULL, ":");
                }
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(NULL);
            }
        }
    }
    free(command);
    return 0;
}
