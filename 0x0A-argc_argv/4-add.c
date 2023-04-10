#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints Addition line.
 * @argc: Arguments count.
 * @argv: Arguments.
 *
 * Return: Number has symbols - 1.
 *         Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	int i = 1;
	int digit;
	int sum = 0;

	while (i < argc)
	{
		for (digit = 0; argv[i][digit]; digit++)
		{
			if (argv[i][digit] < '0' || argv[i][digit] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[num]);
		i++;
	}

	printf("%d\n", sum);

	return (0);
}
