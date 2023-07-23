#ifndef SHELL_H
#define SHELL_H
#define MAX_COMMAND_LENGTH 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h> 

#define BUFFER_SIZE 1024
#define MAX_ARGS 10
#define INITIAL_BUFFER_SIZE 64

extern char **environ;

/**
 * struct liststr - list
 * @num: number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_n;

typedef struct getinfo
{
	list_n *env;
} info_d;


void tokenizeCommand(char *command, char **args);
void print_environment();
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)

#endif
