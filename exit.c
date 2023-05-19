#include "main.h"

int ex(char *line)
{
	int i, status, num, id;
	char *line_copy;

	line_copy = strdup(line);
	line_copy = _strtok(line_copy, " ");
	line_copy = _strtok(NULL, " ");

	if (line_copy == NULL)
		exit(0);

	num = _atoi(line_copy);
	free(line_copy);
	exit(num);
	return(num);
}