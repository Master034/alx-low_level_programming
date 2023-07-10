#include "main.h"

/**
 * create_file - append content to file
 * @filename: file path
 * @text_content: content
 * Return: chars read
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w;
	int size;
	char *buff;

	if (!filename)
	{
		return (-1);
	}
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (!text_content)
	{
		close(fd);
		return (1);
	}
	size = strlen(text_content);
	buff = malloc(sizeof(char) * size);
	if (!buff)
	{
		close(fd);
		return (-1);
	}
	w = write(fd, text_content, size);
	if (w == -1)
	{
		close(fd);
		free(buff);
		return (-1);
	}
	close(fd);
	free(buff);
	return (1);
}
