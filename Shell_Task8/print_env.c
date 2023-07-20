#include "shell.h"

/**
 * print_environment - Prints the Environment
 * Return: void
 */ 
void print_environment()
{
    char **env = environ;
    
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
