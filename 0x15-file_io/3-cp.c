#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO(int stat, int fd, char *filename, char mode);
/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: arguments passed
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int src, dest, n_read = 1024, wrote, close_src, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	check_IO(src, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO(dest, -1, argv[2], 'W');
	while (n_read == 1024)
	{
		n_read = read(src, buffer, sizeof(buffer));
		if (n_read == -1)
			check_IO(-1, -1, argv[1], 'O');
		wrote = write(dest, buffer, n_read);
		if (wrote == -1)
			check_IO(-1, -1, argv[2], 'W');
	}
	close_src = close(src);
	check_IO(close_src, src, NULL, 'C');
	close_dest = close(dest);
	check_IO(close_dest, dest, NULL, 'C');
	return (0);
}

/**
 * check_IO - checks if a file can be opened or closed
 * @stat: file descriptor of the file to be opened
 * @filename: name of the file
 * @mode: closing or opening
 * @fd: file descriptor
 *
 * Return: void
 */
void check_IO(int stat, int fd, char *filename, char mode)
{
	int exit_code = 0;
	const char *error_message = NULL;
	
	if (stat == -1)
	{
		switch (mode)
		{
			case 'C':
				error_message = "Error: Can't close fd";
				exit_code = 100;
				break;
			case 'O':
				error_message = "Error: Can't read from file";
				exit_code = 98;
				break;
			case 'W':
				error_message = "Error: Can't write to";
				exit_code = 99;
				break;
			default:
				break;
		}
		if (error_message)
		{
			dprintf(STDERR_FILENO, "%s %d", error_message, fd);
			if (filename)
			{
				dprintf(STDERR_FILENO, " - %s", filename);
			}
			dprintf(STDERR_FILENO, "\n");
			exit(exit_code);
		}
	}
}
