#include "shell.h"

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
    char *original_dest = dest;
    
    while (*dest != '\0') {
        dest++;
    }
    for (; *src != '\0'; src++, dest++) {
        *dest = *src;
    }
    *dest = '\0';
    return (original_dest);
}

/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    char *original_dest = dest;
	size_t i;
    
    while (*dest != '\0') {
        dest++;
    }
    for (i = 0; i < n && *src != '\0'; i++) {
        *dest++ = *src++;
    }

    *dest = '\0';
    return (original_dest);
}
