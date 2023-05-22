#include "main.h"
/**
 * main - Function that run SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * @env: The shell environment
 * Return: .
*/
int main(int argc, char *argv[], char **env)
{
	char *line = NULL, *command, **cmd_argv = {NULL}, *environment[] = {NULL};
	size_t len = 0;
	ssize_t read;
	int status = 0, count = 0;

	if (isatty(STDIN_FILENO))
	{
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
			if (strcmp(line, "\n") == 0)
				continue;
			line = handle_new_line(line);
			command = is_excutable(line); 
			if(is_builtin(line, env, status) != -1)
				continue;
			else if (command != NULL)
			{
				cmd_argv = generate_argv(line);
				excute(command, cmd_argv, environment, &status);
				print_error(argv[0], count, WEXITSTATUS(status), line); //permision denied
			}
			else if (command == NULL)
			{
				excute_notFound(line, cmd_argv, environment, &status);
				print_error(argv[0], count, WEXITSTATUS(status), line);
			}
			free(command);
		}
		free(line);
	}
	return (0);
}
