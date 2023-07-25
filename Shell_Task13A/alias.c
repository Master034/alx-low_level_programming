#include "shell.h"
int num_aliases = 0;
AliasInfo *aliases = NULL;

void handle_alias_command(char **args) {
    int i;
    char *arg = NULL;
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

            if (_strchr(arg, '=') != NULL) {
                value = _strtok(NULL, "=");
                set_alias(name, value);
            } else {
                AliasInfo *alias = find_alias(name);
                if (alias != NULL) {
                    printf("%s='%s'\n", alias->name, alias->value);
                } else {
                    printf("Alias '%s' not found.\n", name);
                }
            }
        }
    }
}

void set_alias(const char *name, const char *value) {
       AliasInfo *alias = find_alias(name);
    
    if (alias != NULL) {
        free(alias->value);
        alias->value = strdup(value);
    } else {
        alias = (AliasInfo *)malloc(sizeof(AliasInfo));
        if (alias == NULL) {
            perror("set_alias: malloc");
            return;
        }
        alias->name = strdup(name);
        alias->value = strdup(value);
        alias->next = NULL;
        alias->next = aliases;
        aliases = alias;
    }
}

void print_alias(const char *name) {
    AliasInfo *alias = find_alias(name);
    
    if (alias != NULL) {
        printf("%s='%s'\n", alias->name, alias->value);
    } else {
        printf("Alias '%s' not found.\n", name);
    }
}

AliasInfo *find_alias(const char *name) {
    AliasInfo *current = aliases;
    
    while (current != NULL) {
        if (_strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void free_alias_list() {
    AliasInfo *current = aliases;
    while (current != NULL) {
        AliasInfo *next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
    aliases = NULL;
}
