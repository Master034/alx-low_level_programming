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

	for (i = 0; i <= 9; i++)
	{
		for (j = i; j <= 9; j++)
		{
			putchar(i + '0');
			if (j != i)
			{
				putchar(j + '0');
			}
			if (i != 9 || j != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
		putchar('\n');
		return (0);


}
