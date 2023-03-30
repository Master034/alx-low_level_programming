#include "main.h"

/**
 * _strncat - function that concatenates two strings
 * @dest: appended upon
 * @src:  end of dest
 * @n: number of bytes
 * Return: new concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int a = 0, b = 0;

	while (dest[a++])
		b++;

	for (a = 0; src[a] && a < n; a++)
		dest[b++] = src[a];

	return (dest);
}
