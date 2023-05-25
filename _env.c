#include "main.h"
/**
 * _env - Function that ptint env command
 *
 * Return: .
*/
void _env(int *status)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	*status = 0;
}
