#include "main.h"
/**
 * is_builtin - Function that check built ins
 * @programe: Programe_name
 * @count: Count commands
 * @status: Stat of process
 * @line: The line
 * @ml: line
 * Return: .
*/
int is_builtin(char *programe, char *line, int *status, int count, char *ml)
{
	int i, flag = 1;
	char *line_copy;
	char *built_cmd[] = {"exit", "env", "echo"};

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(line_copy, built_cmd[i]) == 0)
		{
			flag = 0;
			free(line_copy);
			break;
		}
	}
	switch (i)
	{
		case 0:
			ex(line, status, count, programe, ml);
			break;
		case 1:
			_env();
			break;
	}
	if (flag)
	{
		free(line_copy);
		return (-1);
	}
	else
		return (i);
}
