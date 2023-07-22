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
    for (i = 0 ; args[i] != NULL; i++)
        free(args[i]);
    if (args[0] != NULL)
        free(command);
    exit(exit_status);
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
            {
                handle_exit(command, args);
            }
            if (fork() == 0)
            {
                execve(args[0], args, NULL);
                while (path_token != NULL) {
                    snprintf(path_command, BUFFER_SIZE, "%s/%s", path_token, args[0]);
                    execve(path_command, args, environ);
                    path_token = strtok(NULL, ":");
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
