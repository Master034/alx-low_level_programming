#include "main.h"

/**
 * print_most_numbers - Print numbers between 0 and 9.
 * Return: void
 */

void print_most_numbers(void)
{
	for (i = 0 ; i < 10 ; i++)
	{
		if (i != 2 && i != 4)
		{
			_putchar(i);
		}
	}
	_putchar('\n');
}
