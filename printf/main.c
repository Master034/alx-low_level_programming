#include "main.h"

int main()
{
	void *ptr = malloc(sizeof(int));
	unsigned int b = 98;
	int num = 101;
	short int h_value = 456;
	long int l_value = 789;

	_printf("Hello, %s! Today is %c. and %b \n", "John", 'S',b);
	_printf("Octal %o \n", b);
	_printf("Unsigned int %u \n",b);
	_printf("Hexadecimal %x \n", b);
	_printf("Hexadecima Upper %X \n", b);
	_printf("%S\n", "Best\nSchool");
	_printf("Pointer value: %p\n", ptr);
	_printf("Number with '+' flag: %+d\n", num);
	_printf("Long Integer (%%ld): %ld\n", l_value);
	_printf("Long Unsigned Integer (%%lu): %lu\n", l_value);
	_printf("Short Integer (%%hi): %hi\n", h_value);
	free(ptr);
	return (0);
}
