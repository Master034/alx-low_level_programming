#include "main.h"

/**
 * get_endianness - Gets endianes
 */

int get_endianness(void)
{
	unsigned int num;
	char *ptr = (char *)&num;

	num = 1;
	if (*ptr == 1)
		return (1);
	return (0);
}
