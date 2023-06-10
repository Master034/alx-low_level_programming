#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of characters
 * initializes with specific character
 * @size:size of string
 * @c:Character to initialize with
 * Return:Pointer to creted string or Null is size is 0
 */

char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	if (size == 0)
		return (NULL);

	p = (char *) malloc(sizeof(char) * size);

	if (p == NULL)
		return (0);

	for (i = 0; i < size; i++)
	{
		p[i] = c;
	}
	*(p + i) = '\0';
	return (p);
}
