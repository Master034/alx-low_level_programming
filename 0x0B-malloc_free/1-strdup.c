#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new space in memory
 *  that contains copy of string passed.
 *  @str: string to write to memory
 *  Return: a pointer to the string or NULL
 */
char *_strdup(char *str)
{
	char *dupstr;
	unsigned int i;
	int j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		j++;

	dupstr = (char *)malloc(i + 1 * sizeof(char));

	if (dupstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i]; i++)
		dupstr[i] = str[i];

	dupstr[j] = '\0';

	return (dupstr);
}
