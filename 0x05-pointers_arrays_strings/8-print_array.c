#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: int type array pointer
 * @n: int type integer
 * Return: void
 */

void print_array(int *a, int n)
{
	int p = 0;

	for (n--; n >= 0; n--, p++)
	{
		printf("%d", a[p]);
		if (n > 0)
		{
		printf(", ");
		}
	}
	printf("\n");
}
