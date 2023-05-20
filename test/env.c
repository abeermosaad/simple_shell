#include "main.h"

char *_getenv1(char *c)
{
	char **env = environ, *tok;
	int len = 0;

	len = (int)strlen(c);
	while(*env)
	{
		if(strncmp(c, *env, len) == 0 && (*env)[len] == '=')
		{
			tok = strtok(*env, "=");
			tok = strtok(NULL, "=");
			return (tok);
		}
		env++;
	}
	return (NULL);
}