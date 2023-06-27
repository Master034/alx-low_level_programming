#include "main.h"


void _print_integer(unsigned int num, int base, int uppercase, flags_t flags)
{

	char buffer[sizeof(unsigned int) * 8 + 1];
	char digits[] = "0123456789abcdef";
	int index = sizeof(buffer) - 1;
	
	if (flags.plus && num >= 0)
	{
		write(STDOUT_FILENO, "+", 1);
	}
	else if (flags.space && num >= 0)
	{
		write(STDOUT_FILENO, " ", 1);
	}

	if (num == 0)
	{
		_putchar('0');
		return;
	}
	if (uppercase)
		digits[10] = 'A';
	
	buffer[index] = '\0';
	while (num > 0)
	{
		buffer[--index] = digits[num % base];
		num /= base;
	}
	while (buffer[index] != '\0')
	{
		_putchar(buffer[index]);
		index++;
	}
}
