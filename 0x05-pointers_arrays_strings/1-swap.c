#include "main.h"

/**
 * swap_int - Swapp the value of 2 inputs
 * @a: First parameter
 * @b: Second Parameter
 * Return: Void
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
