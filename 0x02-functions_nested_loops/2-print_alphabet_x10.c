#include "main.h"

/**
 * print_alphabet_x10 - Prints Alphabets 10 times
 *
 */

void print_alphabet_x10(void)
{
	int p;
	int r;

	for (p = 0 ; p < 10; p++)
	{
		for (r = 'a'; r <= 'z'; r++)
		{
			_putchar(r);
		}
		_putchar('\n');
	}
}
