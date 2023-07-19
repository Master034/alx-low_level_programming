#include "shell.h"

int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while (1)
    {
        printf("simple_shell$ ");
        characters = getline(&command, &bufsize, stdin);
        
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
        {
            command[characters - 1] = '\0';
        }
        if (command[0] != '\0')
        {
            if (fork() == 0)
            {
                char **args = malloc(sizeof(char *) * 2);
                args[0] = command;
                args[1] = NULL;
                execve(command, args, NULL);
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
