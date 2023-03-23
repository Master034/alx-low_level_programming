#include "main.h"

/**
 * print_diagonal - prints diagonal line.
 * @n: Parameter Input
 * Return: void
 *
 */

void print_diagonal(int n)
{
	int x = 0, xx;

	while (x < n && n > 0)
	{
		xx = 0;
		while (xx < x)
		{
			_putchar(' ');
			xx++;
		}

		_putchar('\\');
		_putchar('\n');
		x++;
	}
	if (x == 0)
		_putchar('\n');
}
