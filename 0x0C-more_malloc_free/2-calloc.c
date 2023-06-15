#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for Array
 * @nmemb:Number of elements
 * @size:Size of elements
 * Return: Pointer to the string array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		*((char *)(ptr) + i) = 0;
	return (ptr);
}
