#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	int i = 0;
	int m3 = 3;
	int m5 = 5;
	int sum = 0;
	int max = 1024;

	while (i == 0)
	{
		if (m3 < max)
		{
			sum += m3;
			m3 += 3;
		}
		if (m5 < max && (m5 % 3) != 0)
		{
			sum += m5;
			m5 += 5;
		}
		else if (m5 % 3 == 0)
		{
			m5 += 5;
		}
		if (m3 >= max && m5 >= max)
		{
			i = 1;
		}
	}
	printf("%d\n", sum);
	return (0);
}
