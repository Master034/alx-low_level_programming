#include "main.h"

void _print_pointer(void *ptr)
{
    unsigned long value = (unsigned long)ptr;
    _print_integer(value, 16, 0);
}
