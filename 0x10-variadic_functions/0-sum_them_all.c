#include "variadic_functions.h"

/**
 * sum_them_all - Get the sum of numbers
 * @n:Argunemnts count
 * Return:Sum of all numbers
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);
	sum = 0;
	va_start(args, n);
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	va_end(args);
	return (sum);
}
