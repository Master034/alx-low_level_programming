#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcode.
 * @argc: arguments count
 * @argv: Array of argument pointers.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int bytes, index;
	int (*add)(int, char **) = main;
	unsigned char opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (index = 0; index < bytes; index++)
	{
		opcode = *(unsigned char *)add;
		printf("%.2x", opcode);

		if (index == bytes - 1)
			continue;
		printf(" ");

		add++;
	}

	printf("\n");

	return (0);
}
