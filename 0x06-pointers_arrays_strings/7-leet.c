#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to be encoded
 * Return: encoded string
 */

char *leet(char *str)
{
	int a, b;
	char s1[] = "aeotl";
	char S1[] = "AEOTL";
	char s2[] = "43071";

	for (a = 0; str[a] != '\0'; a++)
	{
		for (b = 0; b < 5; b++)
		{
			if (str[a] == s1[b] || str[a] == S1[b])
			{
				str[a] = s2[b];
				break;
			}
		}
	}
	return (str);
}
