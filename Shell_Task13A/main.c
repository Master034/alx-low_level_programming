#include "shell.h"

/**
 * main - Main function for the simple shell.
 * Return: 0 on success.
 */
int main(void)
{
	size_t bufsize = 0;
	ssize_t characters;
	char *path_env = getenv("PATH");
	char *path_token = _strtok(path_env, ":");
	char *command = NULL;
	char path_command[BUFFER_SIZE];
	int overwrite = 0;
	
	while (1)
	{
		printf("simple_shell$ ");
		characters = _getline(&command, &bufsize, stdin);
		if (characters == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (characters > 0 && command[characters - 1] == '\n')
			command[characters - 1] = '\0';
		handle_command(command, &path_token, path_command, overwrite);
	}
	free_alias_list();
	free(command);
	return (0);
}

/**
 * handle_command - Handle the entered command.
 * @command: The command entered by the user.
 * @path_token: The current token in the PATH environment variable.
 * @path_com: Buffer to store the command with path.
 * @ow: Flag to indicate an existing environment variable.
 * Return: void.
 */
void handle_command(char *command, char **path_token, char *path_com, int ow)
{
	if (_strcmp(command, "exit") == 0)
		_handle_exit(command);
	else if (_strcmp(command, "env") == 0)
		print_environment();
	else if (command[0] != '\0')
	{
		char *args[MAX_ARGS];
		tokenizeCommand(command, args);
		if (_strcmp(args[0], "exit") == 0)
			_handle_exit(args[0]);
		else if (_strcmp(args[0], "alias") == 0)
			handle_alias_command(args);
		else if (_strcmp(args[0], "setenv") == 0)
			_setenv(args[1], args[2], ow);
		else if (_strcmp(args[0], "cd") == 0)
			_cd(args[1]);
		else if (fork() == 0)
		{
			execute_command(args, path_token, path_com);
i		}
		else
			wait(NULL);
	}
}

/**
 * execute_command - Execute the command.
 * @args: The command and its arguments.
 * @path_token: The current token in the PATH environment variable.
 * @path_command: Buffer to store the command with path.
 * Return: void.
 */
void execute_command(char **args, char **path_token, char *path_command)
{
	execve(args[0], args, NULL);
	while (*path_token != NULL)
	{
		snprintf(path_command, BUFFER_SIZE, "%s/%s", *path_token, args[0]);
		execve(path_command, args, environ);
		*path_token = _strtok(NULL, ":");
	}
	perror("execve");
	exit(EXIT_FAILURE);
}
