#include "main.h"
/**
 * ex - Function that exit
 * @line: From user
 * @stat: Stat of process
 * @count: Count commands
 * @programe: Programe_name
 * @ml: the line
 * Return: status
*/
int ex(char *line, int *stat, int count, char *programe, char *ml)
{
	int exit_status = 0, len, is_valid = 1, i;
	char *status;
	char *line_copy;

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	status = _strtok(NULL, " ");
	if (!status)
	{
		free(ml);
		free(line_copy);
		exit(*stat);
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
			free(line);
			free(line_copy);
			exit(exit_status);
		} else
		{
			*stat = 2;
			print_error(programe, count, *stat, line);
			free(line_copy);
		}
	} return (exit_status);
}
