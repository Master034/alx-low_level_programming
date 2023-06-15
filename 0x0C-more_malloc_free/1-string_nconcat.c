#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatanates two strings
 * @s1:First String
 * @s2:Second String
 * @n:THe numbers of bytes to add
 * Return: Pointer to the new string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len2, len1, n2, total, i, j;
	char *s3;

	n2 = n;
	if (s2 == NULL)
		s2 = "";
	if (s1 == NULL)
		s1 = "";
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n2 >= len2)
		n2 = len2;

	total = len1 + n2 + 1;
	s3 = malloc(sizeof(char) * total);
	if (s3 == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		s3[i] = s1[i];
	for (j = 0; j < n2; j++)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';

	return (s3);


}
