#include "shell.h"

/**
 * _getline - Gets the line
 * Return: Number of Characters
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t i = 0;
    
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1; // Invalid input parameters
    }
    if (*lineptr == NULL || *n < INITIAL_BUFFER_SIZE) {
        *lineptr = (char*)malloc(INITIAL_BUFFER_SIZE);
        if (*lineptr == NULL) {
            perror("Memory allocation failed");
            return -1;
        }
        *n = INITIAL_BUFFER_SIZE;
    }
    while ((c = fgetc(stream)) != EOF) 
    {
        if (i >= *n - 1) 
        { 
            size_t new_size = *n * 2;
            char* temp = (char*)realloc(*lineptr, new_size);
            if (temp == NULL) {
                perror("Memory reallocation failed");
                return -1;
            }
            *lineptr = temp;
            *n = new_size;
        }
        (*lineptr)[i] = c;
        i++;
        if (c == '\n')
            break;
    }
    if (i == 0)
        return -1;
    (*lineptr)[i] = '\0'; 
    return i; 
}
