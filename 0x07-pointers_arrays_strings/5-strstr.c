#include "main.h"

/**
 * _strstr - search for a substring within a string
 * @haystack: The large string
 * @needle: The substring
 * Return: Pointer to the first occurence of the substring
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
