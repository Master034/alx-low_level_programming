#include "shell.h"


void displayPrompt()
{
	printf("$ ");
}

int executeCommand(const char* command)
{
	int status = system(command);
	if (status == -1)
	{
		perror("Command execution error");
		return -1;
	}
	return status;
}

int main()
{
	char command[MAX_COMMAND_LENGTH];
	
	while (1)
	{
		displayPrompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
			break;
		command[strcspn(command, "\n")] = '\0'; 
		if (strlen(command) == 0)
			continue; 
		if (executeCommand(command) == -1)
			continue; 
	}
	printf("Shell terminated.\n");
	return 0;
}
