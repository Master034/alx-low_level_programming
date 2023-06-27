#include "main.h"

int main()
{
	unsigned int b = 98;
	_printf("Hello, %s! Today is %c. and %b \n", "John", 'S',b);
	_printf("Octal %o \n", b);
	_printf("Unsigned int %u \n",b);
	_printf("Hexadecimal %x \n", b);
	_printf("Hexadecima Upper %X \n", b);
	return (0);
}
