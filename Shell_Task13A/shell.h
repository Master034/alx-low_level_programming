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
#define MAX_COMMANDS 10
#define MAX_ALIASES 50

typedef struct AliasInfo {
    char *name;
    char *value;
    struct AliasInfo *next;
} AliasInfo;

extern char **environ;

void tokenizeCommand(char *command, char **args);
void print_environment();
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char* _strtok(char* str, const char* delim);
void _handle_exit(char *command);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void _cd(const char *path);
void execute_commands(const char *commands);
AliasInfo *find_alias(const char *name);
void handle_alias_command(char **args);
void set_alias(const char *name, const char *value);
void print_alias(const char *name);
void free_alias_list();

int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
const char* _strpbrk(const char* str, const char* charSet);
const char *_strchr(const char *s, const char c);
char* _getenv(const char* name);

#endif
