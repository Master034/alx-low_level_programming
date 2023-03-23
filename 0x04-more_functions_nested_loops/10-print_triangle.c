#include "main.h"

/**
 * print_triangle - a function that prints a triangle
 * @size: size of the triangle
 * Return: triangle of '#'s
 */
void print_triangle(int size)
{
	int k;
	int ro;
	int tr;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (ro = 0; ro <= (size - 1); ro++)
		{
			for (k = 0; k < (size - 1) - ro; k++)
			{
				_putchar(' ');
			}
			for (tr = 0; tr <= ro; tr++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
