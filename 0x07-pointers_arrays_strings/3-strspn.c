#include "main.h"

/**
 * _strspn - calculate the leghth of the initial segment of a string
 * @s: pointer to the string to be searched
 * @accept: pointer to null terminated set
 * Return: Length of the initial segment
 */

unsigned int _strspn(char *s, char *accept)
{
	int a;
	unsigned int bytes = 0;

	while (*s)
	{
		for (a = 0; accept[a]; a++)
		{
			if (*s == accept[a])
			{
				bytes++;
				break;
			}

			else if (accept[a + 1] == '\0')
			{
				return (bytes);
			}
		}
		s++;
	}

	return (bytes);
}
