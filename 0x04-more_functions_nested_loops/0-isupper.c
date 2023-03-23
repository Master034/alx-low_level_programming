#include "main.h"
#include "ctype.h"

/**
 * _isupper - checks if the character is upper or lower case.
 * @c: parameter input
 *
 * Return: Reurn 1 if uppercase, 0 if lowerase.
 */
int _isupper(int c)
{
	if (isupper(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
