#include "shell.h"

void free_command_list(char **command_list, int num_commands);
void split_commands_by_semicolon(const char *commands, char **command_list, int *num_commands);

void split_commands_by_semicolon(const char *commands, char **command_list, int *num_commands)
{
    char *commands_copy = strdup(commands);
    char *token = NULL;
    
    if (commands_copy == NULL)
    {
        perror("split_commands_by_semicolon: strdup");
        *num_commands = 0;
        return;
    }

    token = _strtok(commands_copy, ";");
    *num_commands = 0;
    while (token != NULL)
    {
        command_list[*num_commands] = strdup(token);
        (*num_commands)++;
        token = _strtok(NULL, ";");
    }

    free(commands_copy);
}

void free_command_list(char **command_list, int num_commands)
{
    int i;
    
    for (i = 0; i < num_commands; i++)
    {
        free(command_list[i]);
    }
}

void execute_single_command(char *command) {
    int len, arg_count = 1;
    char *token, *args[MAX_ARGS];
    pid_t pid;

    while (*command == ' ')
        command++;
    len = strlen(command);
    while (len > 0 && command[len - 1] == ' ')
        command[--len] = '\0';

    if (command[0] != '\0') {
        args[0] = command;
        token = _strtok(command, " ");
        while (token != NULL) {
            while (*token == ' ')
                token++;
            len = strlen(token);
            while (len > 0 && token[len - 1] == ' ')
                token[--len] = '\0';

            if (token[0] != '\0') {
                args[arg_count++] = token;
                if (arg_count >= MAX_ARGS - 1)
                    break;
            }

            token = _strtok(NULL, " ");
        }

        args[arg_count] = NULL;
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execve(args[0], args, environ);
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
}

void handle_logical_op(char **command_list, int *index, int should_execute) {
    if (should_execute) {
        execute_single_command(command_list[*index]);
    }
    (*index)++;
}

void execute_commands(const char *commands) {
    char *command_list[MAX_COMMANDS];
    int num_commands, i;
    char *token;
    int should_execute = 1;

    split_commands_by_semicolon(commands, command_list, &num_commands);

    for (i = 0; i < num_commands; i++) {
        should_execute = strstr(command_list[i], "&&") == NULL;
        
        token = _strtok(command_list[i], "&&||");
        while (token != NULL) {
            handle_logical_op(command_list, &i, should_execute);

            if (strcmp(token, "&&") == 0) {
                should_execute = 1;
            } else if (strcmp(token, "||") == 0) {
                should_execute = 0;
            }

            token = _strtok(NULL, "&&||");
        }
    }

    free_command_list(command_list, num_commands);
}
