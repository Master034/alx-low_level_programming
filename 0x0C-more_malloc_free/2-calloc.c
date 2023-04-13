#include <stdlib.h>
#include "main.h"
/**
  * _calloc - uses malloc to allocate array memory.
  * @nmemb: array count.
  * @size: element size.
  *
  * Return: NULL is size or nmemb == 0.
  * NULL if malloc fails.
  * Pointer to allocated meory - successful.
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		*((char *)(p) + i) = 0;

	return (p);
}
