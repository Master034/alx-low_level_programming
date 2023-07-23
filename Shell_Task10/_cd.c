#include "shell.h"

void update_PWD_env(char *new_path)
{
    char *current_pwd = getenv("PWD");

    if (current_pwd) {
        setenv("OLDPWD", current_pwd, 1);
    }
    setenv("PWD", new_path, 1);
}

int handle_cd_command(char **args)
{
   char cwd[BUFFER_SIZE];
    char current_dir[BUFFER_SIZE] = "";
    char prev_cwd[BUFFER_SIZE];

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {
        char *home_dir = getenv("HOME");
        if (home_dir)
        {
            if (chdir(home_dir) != 0)
            {
                perror("cd");
                return -1;
            }
            update_PWD_env(home_dir);
            return 0;
        }
        else
        {
            fprintf(stderr, "cd: HOME not set\n");
            return -1;
        }
    }
    if (strcmp(args[1], "-") == 0)
    {
        char *old_pwd = getenv("OLDPWD");
        if (old_pwd)
        {
            if (chdir(old_pwd) != 0)
            {
                perror("cd");
                return -1;
            }
            update_PWD_env(old_pwd);
            printf("%s\n", old_pwd);
            return 0;
        }
        else
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return -1;
        }
    }
    if (getcwd(prev_cwd, BUFFER_SIZE) == NULL)
    {
        perror("getcwd");
        return -1;
    }

    if (chdir(args[1]) != 0)
    {
        perror("cd");
        return -1;
    }
    if (getcwd(cwd, BUFFER_SIZE) != NULL)
    {
        update_PWD_env(cwd);
        strncpy(current_dir, cwd, BUFFER_SIZE - 1);
        current_dir[BUFFER_SIZE - 1] = '\0';
    }
    else
    {
        perror("cd");
        return -1;
    }
    printf("%s\n", current_dir);
    return 0;
}
