#include "shell.h"

/**
 * tokenizeCommand - Tokenize a command line input into individual arguments.
 * @command: The command line input to be tokenized.
 * @args: A double pointer to an array of strings to store the tokens (arguments).
 */
void tokenizeCommand(char *command, char **args)
{
    int arg_count = 0;
    char *token = _strtok(command, " ");
    char *var_name;
    char *var_value
    
    while (token != NULL && arg_count < MAX_ARGS - 1)
    {
        if (token[0] == '$') 
        {
            var_name = token + 1;
            var_value = getenv(var_name);
            if (var_value != NULL)
            {
                args[arg_count] = var_value;
            }
            else
            {
                args[arg_count] = token;
            }
        }
        else
        {
            args[arg_count] = token;
        }

        arg_count++;
        token = _strtok(NULL, " ");
    }
    args[arg_count] = NULL;
}
