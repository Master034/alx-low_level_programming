#include <stdio.h>
#include <stdlib.h>

/**
 * main - Adds Positive numbers passed in.
 * @argc: Argument Count
 * @argv: pointers to the arguments.
 * Return: If has Error - 1 Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	int i, x, sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (x = 0; argv[i][x]; x++)
		{
			if (argv[i][x] < '0' || argv[i][x] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);

	return (0);
}
