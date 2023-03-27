#include "main.h"

/**
 * rev_string - reverses a string
 * @s: input
 * Return: Void
 */

void rev_string(char *s)
{
	int a, b, temp;

	a = 0;
	b = 0;
	while (s[b] != '\0')
	{
		b++;
	}
	b--;
	while (b > a)
	{
		temp = s[b];
		s[b--] = s[a];
		s[a++] = temp;
	}
}
