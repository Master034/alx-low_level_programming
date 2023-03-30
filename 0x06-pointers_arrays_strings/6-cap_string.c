#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: word to be capitalized
 * Return: capitalized string
 */

char *cap_string(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		if (str[0] <= 122 && str[0] >= 97)
		{
			str[0] = str[0] - 32;
		}

		if (str[a] == 32 ||
				str[a] == 44 ||
				str[a] == 46 ||
				str[a] == 59 ||
				str[a] == '\t' ||
				str[a] == '\n' ||
				str[a] == '!' ||
				str[a] == '?' ||
				str[a] == '(' ||
				str[a] == ')' ||
				str[a] == '{' ||
				str[a] == '}')
		{
			if (str[a + 1] <= 122 && str[a + 1] >= 97)
			{
				str[a + 1] = str[a + 1] - 32;
			}
		}
	a++;
	}
	return (str);
}
