void tokenizeCommand(char *command, char **args) {
    int arg_count = 0;
    char *token = strtok(command, " ");
    
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    
    args[arg_count] = NULL;
}
