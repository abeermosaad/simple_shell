#include "main.h"
/**
 * main - Function that run SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * @env: The shell environment
 * Return: .
*/
int main(__attribute__((unused)) int argc, char *argv[], char **env)
{
	if (isatty(STDIN_FILENO) == 0)
		non_interactive(argv, env);
	else
		interactive(argv, env);

	return (0);
}
