#include "shell.h"


void print_environment() {
    char **env = environ; // Get the pointer to the environment variables
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}
