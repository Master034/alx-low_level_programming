#include "shell.h"


int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *path_env = getenv("PATH");
    char *path_token = _strtok(path_env, ":");
    char path_command[BUFFER_SIZE];
    pid_t pid = 0;
    int status;

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
        if (strcmp(command, "exit") == 0)
            _handle_exit(command);
        else if (strcmp(command, "env") == 0)
            print_environment();
        else if (command[0] != '\0')
        {
            char *args[MAX_ARGS];
            
            tokenizeCommand(command, args);
            pid = fork();
            if (pid > 0)
            {
                perror("fork");
                free(command);
                exit(EXIT_FAILURE);
            }
            else if(pid == 0)
            {
                execve(args[0], args, NULL);
                while (path_token != NULL) {
                    snprintf(path_command, BUFFER_SIZE, "%s/%s", path_token, args[0]);
                    execve(path_command, args, environ);
                    path_token = _strtok(NULL, ":");
                }
                perror("execve");
                free(command);
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(&status);
                free(command);
                 if (WIFEXITED(status))
                    {
                    int exit_status = WEXITSTATUS(status);
                    printf("%d\n", exit_status);
                    }
            }
        }
    }
    free(command);
    return 0;
}
