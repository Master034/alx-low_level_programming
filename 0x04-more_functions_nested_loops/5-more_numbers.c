#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 * Return: void
 */

void more_numbers(void)
{
	char d, e;
	int a = 0;

	while (a < 10)
	{
		for (d = 0; d <= 14; d++)
		{
			e = d;
			if (d > 9)
			{
				_putchar('1');
				e = d % 10;
			}

			_putchar('0' + e);
		}

		_putchar('\n');
		a++;
	}

}
