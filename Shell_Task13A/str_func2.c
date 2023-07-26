#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
const char *_strdup(const char *str)
{
	size_t len = _strlen(str), i = 0;
	char *duplicate = (char *)malloc((len + 1) * sizeof(char));
	
	if (str == NULL)
	{
		return NULL;
	}
	
	if (duplicate == NULL)
	{
		perror("_strdup: malloc");
		return NULL;
	}
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}
	return (duplicate);
}
