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

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}
/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to a string.
 * @s2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 * Return: Less than 0 if s1 is shorter than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t p;

	for (p = 0; s1[p] && s2[p] && p < n; p++)
	{
		if (s1[p] > s2[p])
			return (s1[p] - s2[p]);
		else if (s1[p] < s2[p])
			return (s1[p] - s2[p]);
	}
	if (p == n)
		return (0);
	else
		return (-15);
}