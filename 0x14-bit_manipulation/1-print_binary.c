#include "main.h"

/**
 * print_binary - Prints the binary of a decimal
 * @n: The decimal
 *
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flag;

	flag = 0;
	while (mask != 0)
	{
		if ((n & mask) != 0)
			flag = 1;
		if (flag)
			_putchar((n & mask) ? '1' : '0');
		mask >>= 1;
	}
	if (!flag)
		_putchar('0');
}
