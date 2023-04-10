#include <stdio.h>

/**
 * main - Prin number of arguments passed.
 * @argc: Number of arguments.
 * @argv: Pointers to arguments.
 *
 * Return: 0 for success.
 */
int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
