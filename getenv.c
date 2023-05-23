#include "main.h"

char *_getenv(char *name)
{
    int name_length;
    char **env;

    if (name == NULL || name[0] == '\0')
        return NULL;
    name_length = (int)strlen(name);

    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
            return (*env + name_length + 1);
    
    }
    return (NULL);
}
/*extern char** environ;

int setenv_builtin(const char* name, const char* value)
{
    char** env;
    int envCount;
    char** newEnviro;

    if (name == NULL || value == NULL || strlen(name) == 0)
    {
        fprintf(stderr, "setenv: Invalid arguments\n");
        return -1;
    }
    env = environ;
    while (*env != NULL)
    {
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
        {
            char* entry = *env;
            size_t entryLen = strlen(name) + strlen(value) + 2;
            char* newEntry = (char*)malloc(entryLen);
            if (newEntry == NULL) {
                perror("setenv: Memory allocation failed");
                return -1;
            }
            strncpy(newEntry, name, entryLen);
            newEntry[entryLen - 1] = '\0';
            strcat(newEntry, "=");
            strcat(newEntry, value);

            free(entry);
            *env = newEntry;
            return 0;
        }
        env++;
    }
    envCount = env - environ;
    newEnviron = (char**)malloc((envCount + 2) * sizeof(char*));
    if (newEnviron == NULL)
    {
        perror("setenv: Memory allocation failed");
        return -1;
    }
    env = environ;
    int i = 0;
    while (*env != NULL)
    {
        newEnviron[i] = *env;
        env++;
        i++;
    }
    size_t entryLen = strlen(name) + strlen(value) + 2;
    char* newEntry = (char*)malloc(entryLen);
    if (newEntry == NULL)
    {
        perror("setenv: Memory allocation failed");
        free(newEnviron);
        return -1;
    }
    strncpy(newEntry, name, entryLen);
    newEntry[entryLen - 1] = '\0';
    strcat(newEntry, "=");
    strcat(newEntry, value);
    newEnviron[i] = newEntry;
    newEnviron[i + 1] = NULL;
    environ = newEnviron;

    return 0;
}*/
