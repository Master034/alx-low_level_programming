#include <stdlib.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strlen - calculate lenght of a string
 * @str: string
 * Return: string length
 */

int _strlen(char *str)
{
	for (int i = 0; str[i] != "\0"; i++)
		;
	return (i);
}

/**
 * string_nconcat - concatenate two strings
 * @s1: first string
 * @s2: second string
 * @n: bytes to cut at string two
 * Return: pointer to concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *output;
	int a, l, i, j;

	a = n;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (a >= _strlen(s2))
		a = _strlen(s2);

	l = _strlen(s1) + a + 1;

	output = malloc(sizeof(*output) * a);
	if (output == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		output[i] = s1[i];
	for (j = 0; j < a; j++)
		output[i + j] = s2[j];
	output[i + j] = '\0';

	return (output);
}
