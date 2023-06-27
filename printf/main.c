#include "main.h"

int main()
{
	void *ptr = malloc(sizeof(int));
	unsigned int b = 98;

	_printf("Hello, %s! Today is %c. and %b \n", "John", 'S',b);
	_printf("Octal %o \n", b);
	_printf("Unsigned int %u \n",b);
	_printf("Hexadecimal %x \n", b);
	_printf("Hexadecima Upper %X \n", b);
	_printf("%S\n", "Best\nSchool");
	_printf("Pointer value: %p\n", ptr);

	free(ptr);
	return (0);
}
