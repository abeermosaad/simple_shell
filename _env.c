#include "main.h"
/**
 * _env - Function that ptint env command
 * @env: environment variables
 * Return: .
*/
void _env(char **env)
{
	char **envir = env;
	int len;

	while ((*envir))
	{
		len = (int)strlen(*envir);
		write(1, *envir, len);
		write(1, "\n", 1);
		envir++;
	}
}
