#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @str: string to be encoded
 * Return: encoded string
 */

char *rot13(char *str)
{
	int a, b;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; str[a] != '\0'; a++)
	{
		for (b = 0; b < 54; b++)
		{
			if (((str[a] <= 'z' && str[a] >= 'a') || (str[a] <= 'Z' && str[a] >= 'A'))
			&& str[a] == input[b])
			{
				str[a] = output[b];
				break;
			}
		}
	}
	return (str);
}
