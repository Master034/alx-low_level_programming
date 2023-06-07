#include "main.h"
int _sqrt_recursive(int n, int start, int end);

/**
 * _sqrt_recursive - Get Square root
 * @n:number
 * @start:start
 * @end:end
 * Return:square root
 */

int _sqrt_recursive(int n, int start, int end)
{
	int mid;
	int square;

	if (start > end)
		return (-1);
	mid = (start + end) / 2;
	square = mid * mid;

	if (square == n)
		return (mid);
	else if (square < n)
		return (_sqrt_recursive(n, mid + 1, end));
	else
		return (_sqrt_recursive(n, start, mid - 1));
}

/**
 * _sqrt_recursion - Return squareroot
 * @n:The number
 * Return:squareroot or -1
 */

int _sqrt_recursion(int n)
{
	return (_sqrt_recursive(n, 0, n));
}
