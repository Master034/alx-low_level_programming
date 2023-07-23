#include "shell.h"
int num_aliases = 0;

void handle_alias_command(char **args) {
    int i;
    char *arg  = NULL;
    char *name = NULL;
    char *value = NULL;
    
    if (args[1] == NULL) {
        for (i = 0; i < num_aliases; i++) {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
        }
    } else {
        for (i = 1; args[i] != NULL; i++) {
            arg = args[i];
            name = _strtok(arg, "=");
            
            if (strchr(arg, '=') != NULL) {
                value = _strtok(NULL, "=");
                set_alias(name, value);
            } else {
                print_alias(name);
            }
        }
    }
}

void set_alias(const char *name, const char *value) {
    int alias_index = find_alias(name);
    
    if (alias_index != -1) {
        free(aliases[alias_index].value);
        aliases[alias_index].value = strdup(value);
    } else {
        if (num_aliases < MAX_ALIASES) {
            aliases[num_aliases].name = strdup(name);
            aliases[num_aliases].value = strdup(value);
            num_aliases++;
        } else {
            printf("Too many aliases. Cannot create alias '%s'.\n", name);
        }
    }
}

void print_alias(const char *name) {
    int alias_index = find_alias(name);
    
    if (alias_index != -1) {
        printf("%s='%s'\n", aliases[alias_index].name, aliases[alias_index].value);
    } else {
        printf("Alias '%s' not found.\n", name);
    }
}

int find_alias(const char *name) {
    int i;
    
    for (i = 0; i < num_aliases; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
