#include "main.h"

/**
 * more_numbers - Print numbers from 0 to 14.
 * Return: void
 */

void more_numbers(void)
{
	int i;
	int x;

	for (i = 0 ; i < 10 ; i++)
	{
		for (x = 0; x < 15; x++)
		{
			_putchar('0' +  x);
		}
		_putchar('\n');
	}
	_putchar('\n');
}
