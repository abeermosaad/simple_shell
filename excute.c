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

	argv = malloc(sizeof(char *) * (_strlen(line) + 1));

	if (!argv)
		perror("malloc");

	argv_idx = _strtok(line, TOK_DELIM);
	while (argv_idx)
	{
		if (argv_idx[0] == '#')
			break;
		argv[i] = argv_idx;
		argv_idx = _strtok(NULL, TOK_DELIM);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * excute - Function That execute the cmd
 * @command: The command
 * @argv: All the arguments after the cmd
 * @env: All environments
 * @status: State of process
 * Return: void
*/
int excute(char *command, char **argv, char *env[], int *status)
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
			exit(126);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		*status = WEXITSTATUS(*status);
	}
	free(argv);
	return (0);
}
