#include "main.h"
/**
 * ex - Function that exit
 * @line: From user
 * Return: status
*/
int ex(char *line)
{
	int exit_status = 0;
	char *status;
	char *line_copy;

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	status = strtok(NULL, " ");

	if (status != NULL)
		exit_status = atoi(status);

	free(line_copy);
	free(line);
	exit(exit_status);
	return (exit_status);
}
