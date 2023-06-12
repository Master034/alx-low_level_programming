#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatanates two string
 * @s1:First String
 * @s2:Second string
 * Return: The concataneted string
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, len1, len2;
	char *s3;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;

	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	len2 += 1;
	s3 = malloc((sizeof(char) * len1) + (sizeof(char) * len2));
	if (s3 == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
	{
		s3[i] = s1[i];
	}
	for (j = 0; s2[j] != '\0'; j++, i++)
	{
		s3[i] = s2[j];
	}
	s3[i] = '\0';
	return (s3);
}
