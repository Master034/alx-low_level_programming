#include "main.h"

/**
 * print_line - prints line.
 * @n: Parameter Input
 * Return: void
 *
 */

void print_line(int n)
{

	int a = 0;

	while (a < n && n > 0)
	{
		_putchar('_');
		a++;
	}
	_putchar('\n');
}
