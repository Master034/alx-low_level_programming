#include "main.h"
int is_prime_number_r(int n, int i);

/**
 * is_prime_number - Checks if Prime Number;
 * @n: Number Passed
 * Return:0 if not 1 otherwise
 */

int is_prime_number(int n)
{
	return (is_prime_number_r(n, n - 1));
}

/**
 * is_prime_number_r - Recursive Check
 * @n:Number
 * @i:Iteration
 * Return: 1 if prime, o otherwise
 */

int is_prime_number_r(int n, int i)
{
	if (n <= 1)
		return (0);
	if (i == 1)
		return (1);
	if (n % i == 0)
		return (0);
	return (is_prime_number_r(n, i - 1));
}
