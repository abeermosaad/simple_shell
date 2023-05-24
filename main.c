#include "main.h"
/**
 * main - Function that run SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: .
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	if (isatty(STDIN_FILENO) == 0)
		non_interactive(argv);
	else
		interactive(argv);

	return (0);
}
