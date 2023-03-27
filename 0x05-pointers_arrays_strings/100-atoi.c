#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: char type string
 * Return: Converted integer
 */

int _atoi(char *s)
{
	int sign = 1;
	int rp = 0;
	int Num;

	for (Num = 0; !(s[Num] >= 48 && s[Num] <= 57); Num++)
	{
		if (s[Num] == '-')
		{
			sign *= -1;
		}
	}

	for (int a = Num; s[a] >= 48 && s[a] <= 57; a++)
	{
		rp *= 10;
		rp += (s[a] - 48);
	}

	return (sign * rp);
}
