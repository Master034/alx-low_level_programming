#include "shell.h"

/**
 * _strtok-Tokenize String
 * @str: The string to tokenize
 * @delim: Delimiter
 * Return: Tokenized array
 */
char* _strtok(char* str, const char* delim)
{
    static char* crnt_str = NULL;
    char* token_start = NULL;
    char* token_end = NULL;
    static bool end_of_string = false;
    
    if (str != NULL)
        crnt_str = str;
    if (crnt_str == NULL || end_of_string)
        return (NULL);
    token_start = crnt_str;
    token_end = strpbrk(crnt_str, delim);
    
    if (token_end == NULL)
        end_of_string = true;
    else
    {
        *token_end = '\0';
        crnt_str = token_end + 1;
    }
    return token_start;
}
