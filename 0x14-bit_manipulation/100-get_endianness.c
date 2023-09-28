#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int p;
	char *k;

	p = 1;
	k = (char *)&p;
	return (*k);
}

