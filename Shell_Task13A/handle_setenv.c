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
    char *new_env_var = NULL;
    
    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
        return -1;
    if (env_var != NULL)
        overwrite = 1;
    if (env_var != NULL && !overwrite)
    {
        printf("Environment variable '%s' already exists. Use 'overwrite' flag to modify.\n", name);
        return 0;
    }
    len_name = _strlen(name);
    len_value = _strlen(value);
    len_total = len_name + 1 + len_value + 1;
    new_env_var = (char *)malloc(len_total);
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

/**
 * _unsetenv - Unset an environment variable.
 * @name: Name of the environment variable to unset.
 * Return: On success, 0. On error, -1 is returned.
 */
int _unsetenv(const char *name)
{
    char **env = environ;
    char *env_var;
    size_t len_name;

    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
        return -1;

    len_name = _strlen(name);
    
    while (*env != NULL)
    {
        env_var = *env;
        if (_strncmp(env_var, name, len_name) == 0 && env_var[len_name] == '=')
        {
            while (*(env + 1) != NULL)
            {
                *env = *(env + 1);
                env++;
            }
            *env = NULL;
            return 0;
        }
        env++;
    }
    fprintf(stderr, "unsetenv: Environment variable '%s' not found.\n", name);
    return -1;
}
