#include "variadic_functions.h"
#include <stdio.h>
/**
 * print_numbers - function that prints numbers.
 * @n: number of arguments
 * @separator: number seperator
 * Return: Always 0.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list my_nums;
	unsigned int count;

	va_start(my_nums, n);

	for (count = 0; count < n; count++)
	{
		printf("%d", va_arg(my_nums, unsigned int));
		if (count < (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	va_end(my_nums);
	printf("\n");
}
