#include "3-calc.h"

/**
 * main -  perfoms the operations
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int arg1, arg2, output;
	char j;
	int (*calc)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	arg1 = atoi(argv[1]);
	arg2 = atoi(argv[3]);

	calc = get_op_func(argv[2]);

	if (!calc)
	{
		printf("Error\n");
		exit(99);
	}

	j = *argv[2];

	if ((j == '/' || j == '%') && arg2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	output = calc(arg1, arg2);

	printf("%d\n", output);

	return (0);
}
