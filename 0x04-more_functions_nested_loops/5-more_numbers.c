#include "main.h"

/**
 * more_numbers - Print numbers from 0 to 14.
 * Return: void
 */

void more_numbers(void)
{
	int i;
	int x;

	while (i = 0 && i < 10)
	{
		while (x = 0 && x < 15)
		{
			_putchar('0' + x);
			x++;
		}
		_putchar('\n');
		i++;
	}
	_putchar('\n');
}
