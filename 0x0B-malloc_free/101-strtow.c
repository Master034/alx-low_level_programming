#include "main.h"
#include <stdlib.h>

/**
 * count_word - counts words in a string
 * @str: string to use
 * Return: number of words
 */
int count_word(char *str)
{
	int a;
	int b;
	int c;

	a = 0;
	c = 0;

	for (b = 0; str[b] != '\0'; b++)
	{
		if (str[b] == ' ')
			a = 0;
		else if (a == 0)
		{
			a = 1;
			c++;
		}
	}
	return (c);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array on success
 *  or NULL on failure.
 */
char **strtow(char *str)
{
	char **matrix, *lst;
	int i, y = 0, len = 0, words;
	int c = 0;
	int start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				lst = (char *) malloc(sizeof(char) * (c + 1));
				if (lst == NULL)
					return (NULL);
				while (start < end)
					*lst++ = str[start++];
				*lst = '\0';
				matrix[y] = lst - c;
				y++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[y] = NULL;

	return (matrix);
}
