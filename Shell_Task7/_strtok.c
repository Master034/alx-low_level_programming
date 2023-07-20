#include "shell.h"

/**
 * _strtok-Tokenize String
 * @str: The string to tokenize
 * @delim: Delimiter
 * Return: Tokenized array
 */
char* _strtok(char* str, const char* delim)
{
    static char* current_str = NULL;
    static bool end_of_string = false;
    
    if (str != NULL)
    {
        current_str = str;
        end_of_string = false;
    }
    if (current_str == NULL || end_of_string)
        return (NULL);
    char* token_start = current_str;
    char* token_end = strpbrk(current_str, delim);

    if (token_end == NULL)
        end_of_string = true;
    else
    {
        *token_end = '\0';
        current_str = token_end + 1;
    }
    return token_start;
}
