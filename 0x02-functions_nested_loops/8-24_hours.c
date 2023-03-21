#include "main.h"

/**
 * jack_bauer -  outputs every minute of the day
 */
void jack_bauer(void)
{
	int m, h;

	for (m = 0; m < 24; m++)
	{
		for (h = 0; h < 60; h++)
		{
			if (m < 10)
			{
				_putchar('0');
				_putchar(m + '0');
			}
			else if (m >= 10)
			{
				_putchar((m / 10) + '0');
				_putchar((m % 10) + '0');
			}
			if (h < 10)
			{
				_putchar(':');
				_putchar('0');
				_putchar(h + '0');
			}
			else if (h >= 10)
			{
				_putchar(':');
				_putchar((h / 10) + '0');
				_putchar((h % 10) + '0');
			}
			_putchar('\n');
		}
	}
}
