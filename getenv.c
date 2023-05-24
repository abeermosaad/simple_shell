#include "main.h"
/**
 * _getenv - Function that get the value of the var
 * @name: var name
 * Return: the value of the var
*/
char *_getenv(char *name)
{
	int name_length;
	char **env;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	name_length = (int)strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
			return (*env + name_length + 1);
	}
	return (NULL);
}
