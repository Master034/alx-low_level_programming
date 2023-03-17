#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 * main - Main Content Here
 *
 * Return: Zero always Success
 */
int main(void)
{
	int i, j;
	
	for (i = 0; i < 100; i++)
	{
		for (j = i; j < 100; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (i > j)
			{
				int temp = i;

				i = j;
				j = temp;
			}
			putchar(i / 10 + '0');
			putchar(i % 10 + '0');
			putchar(' ');
			putchar(j / 10 + '0');
			putchar(j % 10 + '0');
			if (i != 99 || j != 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);

}
