#include "main.h"

/**
 * _strchr - Locates a character in a string , First occurance
 * @s: The string to be searched
 * @c: tha character to be searched
 *
 * Return: pointer to first occurance of  chracter or null pointer.
 */

char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
			return (s + a);
	}

	return ('\0');
}
