#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - Concatanates arguments
 * @ac:argument count
 * @av:Array of arguments
 * Return: Pointer to the new string
 */

char *argstostr(int ac, char **av)
{
	int i, j, total_length = 0;
	char *a, *result;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		total_length += strlen(av[i]) + 1;
	}
	result = (char *)malloc(total_length + 1);

	if (result == NULL)
		return (NULL);

	a = result;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			*result = av[i][j];
			result++;
		}
		*result = '\n';
		result++;
	}
	return (a);
}

