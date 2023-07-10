#include "main.h"

/**
 * read_textfile - reads and prints from a file
 * @filename: path to file
 * @letters: chars to read
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t count, r;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}
	count = read(fd, buffer, letters);

	if (count == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	r = write(STDOUT_FILENO, buffer, count);

	if (r == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	return (count);

}
