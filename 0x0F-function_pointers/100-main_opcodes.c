#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Prints opcodes
 * @num_bytes: Num bytes
 */
void print_opcodes(int num_bytes)
{
	unsigned char *ptr = (unsigned char *)print_opcodes;
	int i;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", *(ptr + i));
	}
	printf("\n");
}

/**
 * main - Main Funtion
 * @argc:Arguments Count
 * @argv:Array Of Arguments
 * Return: 0 for success, 1 Error, 2 Erroor
 */

int main(int argc, char *argv[])
{
	int num_bytes = atoi(argv[1]);

	if (argc != 2)
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	print_opcodes(num_bytes);
	return (0);
}
