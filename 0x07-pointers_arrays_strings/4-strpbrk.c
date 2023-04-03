#include "main.h"

/**
 * _strpbrk - Searches string for a set of bytes
 * @s: string to be seached
 * @accept: the chracter set
 * Return: pointer to first occurance in s
 * or NULL incase of No occurance
 */

char *_strpbrk(char *s, char *accept)
{
	int a;

	while (*s)
	{
		for (a = 0; accept[a]; a++)
		{
			if (*s == accept[a])
				return (s);
		}
		s++;
	}

	return ('\0');
}
