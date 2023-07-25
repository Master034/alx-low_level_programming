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
int _strcmp(const char *s1, const char *s2)
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

/**
 * _strpbrk - Checks for occurennce in a string.
 * @str: Pointer to string.
 * @charSet: Pointer to what to search
 * Return: The string.
 */
const char* _strpbrk(const char* str, const char* charSet) 
{
	const char* c;
	
	for (; *str != '\0'; str++)
	{
		for (c = charSet; *c != '\0'; c++)
		{
			if (*str == *c)
			{
				return (str);
			}
		}
	}
	return NULL;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(const char *s, const char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}
