#include "main.h"

/**
 * append_text_to_file - appends text at the end
 * @filename: filename.
 * @text_content: added content.
 * Return: 1 if the file exists. -1 if it fails or nonexistent
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int size;
	int rw;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);
	if (text_content)
	{
		for (size = 0; text_content[size]; size++)
			;

		rw = write(fd, text_content, size);

		if (rw == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
