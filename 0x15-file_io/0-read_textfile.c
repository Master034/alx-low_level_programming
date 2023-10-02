#include "main.h"

/**
 * read_textfile - Read and print text from a file.
 * @filename: The name of the file to be read.
 * @letters: The number of characters to read and print.
 * Return:
 * On success, the number of characters read and printed. On error, -1
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytesRead, bytesWritten;
	char *buffer;
	FILE *file;

	if (!filename)
		return (0);
	file = fopen(filename, "r");
	if (!file)
		return (0);
	buffer = (char *)malloc(letters + 1);
	if (!buffer)
	{
		fclose(file);
		return (0);
	}
	bytesRead = fread(buffer, 1, letters, file);
	if (bytesRead < 0)
	{
		free(buffer);
		fclose(file);
		return (0);
	}
	buffer[bytesRead] = '\0';
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten != bytesRead)
	{
		free(buffer);
		fclose(file);
		return (0);
	}
	free(buffer);
	fclose(file);
	return (bytesRead);
}
