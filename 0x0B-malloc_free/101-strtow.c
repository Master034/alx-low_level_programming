#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_space - checks for white spaces
 * @c: character passed
 * Return: Returns space
 */

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - count words
 * @str:String to count
 * Return:Number of characters
 */

int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (is_space(*str))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * strtow - Breaks down a string into words
 * @str: The String to break down
 * Return:Pointer to array containing the words
 */
char **strtow(char *str)
{
	char **words, *start = NULL;
	int in_word = 0, word_length, word_index = 0, i, num_words = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	num_words = count_words(str);
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (is_space(*str))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			start = str;
		}
		if (!in_word && start != NULL)
		{
			word_length = str - start;
			words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
			if (words[word_index] == NULL)
			{
				for (i = 0; i < word_index; i++)
				{
					free(words[i]);
				}
				free(words);
				return (NULL);
			}
			strncpy(words[word_index], start, word_length);
			words[word_index][word_length] = '\0';
			word_index++;
			start = NULL;
		}
		str++;
	}
	words[num_words] = NULL;
	return (words);
}
