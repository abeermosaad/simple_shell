#include "main.h"

int is_builtin(built_t command[] ,char *line)
{
	int i;
	char *line_copy;

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	for (i = 0; i < 1; i++)
	{
		if(strcmp(line_copy, command[i].cmd) == 0)
		{	
			free(line_copy);
			return (i);
		}
	}
	free(line_copy);
	return (-1);
}
