#include "main.h"
#include "ctype.h"

/**
 * _isdigit - Checks if the character passed is a digit.
 * @c: Parameter Passed In.
 * Return: Return 0 or 1.
 */

int _isdigit(int c)
{
	if (isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
