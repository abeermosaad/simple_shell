#include "main.h"

void _env(char **env)
{
	char **envir = env;
	int len, i;

	while ((*envir))
	{
		len = (int)strlen(*envir);
		write(1, *envir, len);
		write(1, "\n", 1);
		envir++;
		i++;
	}
}
