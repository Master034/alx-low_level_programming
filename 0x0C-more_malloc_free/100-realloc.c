#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block
 * @ptr: pointer to old allocation
 * @old_size: size of ptr
 * @new_size: new size
 *
 * Return: pointer to new allocation
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *n_ptr;
	char *old_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	n_ptr = malloc(new_size);
	if (!n_ptr)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			n_ptr[i] = old_ptr[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			n_ptr[i] = old_ptr[i];
	}

	free(ptr);
	return (n_ptr);
}
