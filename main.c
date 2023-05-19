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
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, ":) ", sizeof(":) ") - 1);
			read = _getline(&line, &len, stdin);
			if (read == -1)
			{
				write(1, "\n", 1);
				break;
			}
			line = handle_new_line(line);
			if (is_builtin(line))
			{
				/*do something*/
			}
			command = is_excutable(line);
			if (command != NULL)
			{
				argv = generate_argv(line);
				excute(command, argv, env);
			}
			else if (command == NULL)
			{
				perror("command not found");
			}
		}
		free(argv);
		free(line);
	}
	return (0);
}
