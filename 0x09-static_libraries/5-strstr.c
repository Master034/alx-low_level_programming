#include "main.h"

/**
 * _strstr - search for a substring within a string
 * @haystack: The large string
 * @needle: The substring
 * Return: Pointer to the first occurence of the substring
 */

char *_strstr(char *haystack, char *needle)
{
	int a;

	if (*needle == 0)
		return (haystack);

	while (*haystack)
	{
		a = 0;

		if (haystack[a] == needle[a])
		{
			do {
				if (needle[a + 1] == '\0')
					return (haystack);

				a++;
			} while (haystack[a] == needle[a]);
		}
		haystack++;
	}

	return ('\0');
}
