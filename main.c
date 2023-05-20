#include "main.h"
/**
 * main - Function that run SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * @env: The shell environment
 * Return: .
*/
int main(void)
{
	char *line = NULL, *command, **argv, *env[] = {NULL};
	size_t len = 0;
	int i;
	ssize_t read;
	built_t cmd[] = {{"exit", ex}}; // egzit kh

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, ":) ", sizeof(":) ") - 1);
			read = getline(&line, &len, stdin);
			if (read == -1)
			{
				write(1, "\n", 1);
				break;
			}
			line = handle_new_line(line);
			i = is_builtin(cmd, line);
			command = is_excutable(line);
			if (i != -1)
			{
				cmd[i].func(line);
			}
			else if (command != NULL)
			{
				argv = generate_argv(line);
				excute(command, argv, env);
			}
			else if (command == NULL)
				perror("command not found");
			free(command);
		}
		free(line);
	}
	return (0);
}
