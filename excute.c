#include "main.h"
/**
 * generate_argv - Function That generate all the arguments
 * @line: take the line from getline function
 * Return: array of strings (Vector)
*/
char **generate_argv(char *line)
{
	char **argv, *argv_idx;
	int i = 0;

	line = handle_new_line(line);
	argv = malloc(sizeof(char *) * (_strlen(line) + 1));

	if (!argv)
		perror("malloc");

	argv_idx = _strtok(line, " ");
	while (argv_idx)
	{
		argv[i] = argv_idx;
		argv_idx = _strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}


void excute(char *command, char **argv, char *env[])
{
	int exc;
	int id;

	id = fork();
	if (id == -1)
		perror("ERROR IN FORK");
	if (id == 0)
	{
		exc = execve(command, argv, env);
		if (exc == -1)
			perror("ERROR IN EXCEUTE");
	}
	else
		wait(NULL);
}
