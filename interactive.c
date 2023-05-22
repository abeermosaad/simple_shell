#include "main.h"

void interactive(char **argv, char *env[])
{
	char *line = NULL, *command, **cmd_argv = {NULL}, *environment[] = {NULL};
	size_t len = 0;
	ssize_t read;
	int status = 0, count = 0, i;

	while (1)
	{
		count++;
		write(1, ":) ", sizeof(":) ") - 1);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			write(1, "\n", 1);
			break;
		}
		line = handle_new_line(line);
		command = is_excutable(line);
		if (_strcmp(line, "\n") == 0)
			continue;
		else if (is_builtin(argv[0], line, env, &status, count) != -1)
			continue;
		else if (command != NULL)
		{
			cmd_argv = generate_argv(line);
			i = excute(command, cmd_argv, environment, &status);
			if (i == 0)
				print_error(argv[0], count, status, line);
		}
		else if (command == NULL)
		{
			excute_notFound(line, cmd_argv, environment, &status);
			print_error(argv[0], count, status, line);
		}
	}
	free(line);
}