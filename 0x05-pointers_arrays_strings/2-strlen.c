#include "main.h"
#include "string.h"

/**
 * _strlen - Prints the length of a string
 * @s: input
 * Return: Length
 */

int _strlen(char *s)
{
	int l;

	l = 0;
	while (*s++)
	{
		l++;
	}
	return(l)

}
