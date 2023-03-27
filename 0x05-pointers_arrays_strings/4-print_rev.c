#include "main.h"

/**
 * print_rev - prints a string, in reverse
 * @s: Pointer to the string
 * Return: void
 */

void print_rev(char *s)
{
	int a = 0;

	while (s[a])
		a++;
	while (a--)
	{
		_putchar(s[a]);
	}
	_putchar('\n');
}
