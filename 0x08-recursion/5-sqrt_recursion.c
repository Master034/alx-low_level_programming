#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input
 * Return: square root
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - find square root recursion
 * @n: input a
 * @a: square root
 * Return: value
 */

int _sqrt(int n, int a)
{
	if (a * a == n)
	{
		return (a);
	}
	else if (a * a < n)
	{
		return (_sqrt(n, a + 1));
	}
	else
	{
		return (-1);
	}
}
