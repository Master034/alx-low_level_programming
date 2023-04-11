#include <stdlib.h>
#include "main.h"

/**
 * *create_array - creates an array of chars and intialize
 * @size: lenght of array
 * @c: The character to initialize
 *
 * Return: pointer to the array (Success), NULL (Error)
 */
char *create_array(unsigned int size, char c)
{
	char *m;
	unsigned int i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	m = (char *) malloc(sizeof(char) * size);

	if (m == NULL)
	{
		return (0);
	}

	for (i = 0; i < size; i++)
	{
		*(p + i) = c;
	}

	*(p + i) = '\0';

	return (p);
}
