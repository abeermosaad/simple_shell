#include "main.h"

int is_builtin(char *line, char **env, int status)
{
	int i, flag = 1;
	char *line_copy;
	char *built_cmd[] = {"exit", "env"};

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	for (i = 0; i < 2; i++)
	{
		if (strcmp(line_copy, built_cmd[i]) == 0)
		{
			flag = 0;
			free(line_copy);
			break;
		}
	}
	switch (i)
	{
		case 0:
			ex(line, status);
			break;
		case 1:
			_env(env);
			break;
	}
	if (flag)
	{
		free(line_copy);
		return(-1);
	}
	else
		return(i);
}
