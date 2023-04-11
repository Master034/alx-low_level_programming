#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: string 0ne
 * @s2: string two
 * Return: NULL if concatenate fails, else return pointer
 * to new string created
 */
char *str_concat(char *s1, char *s2)
{
	char *fin_str;
	int a;
	int b = 0;
	int c = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	for (a = 0; s1[a] || s2[a]; a++)
		c++;

	fin_str = malloc(sizeof(char) * c);

	if (fin_str == NULL)
		return (NULL);

	for (a = 0; s1[a]; a++)
		fin_str[b++] = s1[a];

	for (a = 0; s2[a]; a++)
		fin_str[b++] = s2[a];

	return (fin_str);
}
