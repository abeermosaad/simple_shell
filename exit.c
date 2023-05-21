#include "main.h"
/**
 * ex - Function that exit
 * @line: From user
 * Return: status
*/
int ex(char *line, int stat)
{
	int exit_status = 0, len, is_valid = 1, i;
	char *status;
	char *line_copy;

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	status = _strtok(NULL, " ");
	if (!status)
	{
		free(line_copy);
		free(line);
		exit(WEXITSTATUS(stat));
	}
	len = _strlen(status);
	if (status != NULL)
	{
		if (status[0] == '-')
			is_valid = 0;
		for (i = 0; i < len; i++)
		{
			if (!(status[i] >= '0' && status[i] <= '9'))
			{
				is_valid = 0;
				break;
			}
		}
		if (is_valid)
		{
			exit_status = _atoi(status);
			free(line_copy);
			free(line);
			exit(exit_status);
		}
		else
		{
			free(line_copy);
			stat = 2;
			excute_exit(status, NULL, NULL, &stat);
		}
	}
	return (exit_status);
}
