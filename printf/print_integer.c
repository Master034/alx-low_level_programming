#include "main.h"


void _print_integer(unsigned int num, int base, int uppercase, flags_t *flags)
{

	char buffer[sizeof(unsigned int) * 8 + 1];
	char digits[] = "0123456789abcdef";
	int index = sizeof(buffer) - 1;
	int n2 = num;

	if (flags->plus && n2 >= 0)
	{
		_putchar('+');
	}
	else if (flags->space && n2 >= 0)
	{
		_putchar(' ');
	}

	if (n2 == 0)
	{
		_putchar('0');
		return;
	}
	if (uppercase)
		digits[10] = 'A';
	
	buffer[index] = '\0';
	while (n2 > 0)
	{
		buffer[--index] = digits[n2 % base];
		n2 /= base;
	}
	while (buffer[index] != '\0')
	{
		_putchar(buffer[index]);
		index++;
	}
}
