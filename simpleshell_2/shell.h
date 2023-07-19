#ifndef SHELL_H
#define SHELL_H
#define MAX_COMMAND_LENGTH 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void displayPrompt();
int executeCommand(const char* command);

#endif
