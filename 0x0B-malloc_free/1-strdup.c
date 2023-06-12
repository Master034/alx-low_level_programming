#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup- Duplicates a string
 * @str:String to duplicate
 * Return:Pointer to duplicate string on success
 * returns NULL on failure
 */

char *_strdup(char *str)
{
	char *nstr;
	int i = 0, j = 0;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		i++;
	}
	i += 1;
	nstr = malloc(sizeof(char) * i);
	if (nstr == NULL)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
	{
		nstr[j] = str[j];
	}
	nstr[j] = '\0';
	return (nstr);
}
