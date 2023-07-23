#include "shell.h"


int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;

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
            execute_commands(command);
        }
         
         fflush(stdin);
    }
    free(command);
    return 0;
}