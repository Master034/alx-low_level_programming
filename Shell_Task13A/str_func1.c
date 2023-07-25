#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
	int len = 0;

	if (!s)
		return (len);
	for (len = 0; s[len]; len++)
		;
	return (len);
}
