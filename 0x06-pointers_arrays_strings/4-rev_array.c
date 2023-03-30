#include "main.h"

/**
 * reverse_array - reverses
 * @a: array
 * @n: number of elements
 * Return: Always o
 */

void reverse_array(int *a, int n)
{
	int x = 0, tmp;

	for (x = n - 1; x > n / 2; x--)
	{
		tmp = a[n - 1 - x];
		a[n - 1 - x] = a[x];
		a[x] = tmp;
	}
}
