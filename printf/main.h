#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
void _print_binary(unsigned int num);
void _print_integer(unsigned int num, int base, int uppercase, flags_t flags);
void _print_string(const char *str, flags_t flags );
void _print_pointer(void *ptr);

/**
 * struct flags - struct containing flags
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

#endif
