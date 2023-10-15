#include "shell.h"

// FUNCTIONS TO CREATE
// strchr()
// strncmp()

int _unsetenv(const char *name)
{

}

int _setenv(const char *name, const char *value, int overwrite)
{
    int i, checkName, num_vars = 0;
    char **new_env;

    if (!name || _strchr(name, '='))
        return (-1);
    for (i = 0; environ[i]; i++)
    {
        checkName = strncmp(environ[i], name, _strlen(name));
        if (checkName == 0 && environ[i][_strlen(name)] == '=')
        {
            if (!overwrite)
                return (0);
            free(environ[i]);
            environ[i] = (char *)malloc(_strlen(name) + _strlen(value) + 2);
            if (!environ[i])
                return (-1);
            sprintf(environ[i], "%s=%s", name, value);
            return (0);
        }
    }
    while (environ[num_vars])
        num_vars++;
    new_env = (char **)malloc((num_vars + 2) * sizeof(char *));
    if (!new_env)
        return (-1);
    for (int i = 0; i < num_vars; i++)
        new_env[i] = environ[i];
    new_env[num_vars] = (char *)malloc(_strlen(name) + _strlen(value) + 2);
    if (!new_env[num_vars])
        return (-1);
    sprintf(new_env[num_vars], "%s=%s", name, value);
    new_env[num_vars + 1] = NULL;

    environ = new_env;
    return (0);
}

/**
 * _getenv - Get variable form PATH
 * @variable: Name of variable.
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */

char **_getenv(const char *variable) {
    int len;
    char **env_var;
    
    if (variable == NULL || *variable == '\0' || environ == NULL)
        return NULL;
    len = _strlen(variable);
    for (env_var = environ; *env_var; env_var++) 
    {
        if (_strncmp(variable, *env_var, len) == 0 && (*env_var)[len] == '=') {
            return env_var;
        }
    }

    return NULL;
}







