#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints Name given
 * @name: The name passed
 * @f: Function Pointer
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
