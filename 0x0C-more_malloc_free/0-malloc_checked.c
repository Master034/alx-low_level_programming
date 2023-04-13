#include <stdlib.h>
/**
  * malloc_checked - reserves memory.
  * @b: size to reserve.
  *
  * Return: pointer to memory.
  */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
	{
		exit(98);
	}

	return (p);
}
