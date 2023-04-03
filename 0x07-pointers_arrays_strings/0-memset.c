#include "main.h"

/**
 * _memset - Function that fills memory with a constant byte
 * @s: Pointer to the memory block
 * @b: Value to Set
 * @n: Number of bytes to set to the value
 * Return: pointer to the memory block that was passed
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; n > 0; a++, n--)
	{
		s[a] = b;
	}
	return (s);
}
