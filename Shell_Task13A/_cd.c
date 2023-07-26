#include "shell.h"

/**
 * _cd - Change the current directory of the process.
 * @path: The directory path to change to (can be NULL for default).
 */
void _cd(const char *path)
{
	char current_path[BUFFER_SIZE], new_path[BUFFER_SIZE];

	if (path == NULL || path[0] == '\0')
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			fprintf(stderr, "cd: %s\n", "HOME environment variable not set");
			return;
		}
	}
	if (getcwd(current_path, BUFFER_SIZE) == NULL)
	{
		perror("cd");
		return;
	}
	if (_strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			fprintf(stderr, "cd: %s\n", "OLDPWD not set");
			return;
		}
		printf("%s\n", path);
	}
	if (chdir(path) == -1)
		return;
	if (getcwd(new_path, BUFFER_SIZE) == NULL)
	{
		perror("cd");
		return;
	}
	if (_setenv("PWD", new_path, 1) == -1)
		fprintf(stderr, "cd: %s\n", "Failed to update PWD environment variable");
	if (_setenv("OLDPWD", current_path, 1) == -1)
		fprintf(stderr, "cd: %s\n", "Failed to update OLDPWD environment variable");
}
