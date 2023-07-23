#include "shell.h"

/**
 * custom_setenv - Set a new environment variable or modify an existing one.
 * @name: Name of the environment variable.
 * @value: Value to be set for the environment variable.
 * @overwrite: If 1, overwrite an existing environment variable; if 0, keep it.
 * Return: On success, 0. On error, -1 is returned.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    char *env_var = getenv(name);
    size_t len_name, len_value,len_total;
    
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
        return -1;
    if (env_var != NULL)
        overwrite = 1;
    if (env_var != NULL && !overwrite)
    {
        printf("Environment variable '%s' already exists. Use 'overwrite' flag to modify.\n", name);
        return 0;
    }
    len_name = strlen(name);
    len_value = strlen(value);
    len_total = len_name + 1 + len_value + 1;
    char *new_env_var = (char *)malloc(len_total);
    if (new_env_var == NULL)
    {
        perror("Memory allocation failed");
        return -1;
    }
    snprintf(new_env_var, len_total, "%s=%s", name, value);
    if (putenv(new_env_var) != 0)
    {
        perror("putenv failed");
        free(new_env_var);
        return -1;
    }
    return 0;
}
