#include "main.h"
/**
 * ex - Function that exit
 * @line: From user
 * Return: status
*/
void print_error(char *programe_name, int count, int stat, char *line)//126
{
	if (stat == 126)
	{
		write(2, programe_name, _strlen(programe_name));
		write(2, ": ", 2);
		write(2, "1", 1);
		write(2, ": ", 2);
		write(2, "ls", 2);
		write(2, ": ", 2);
		write(2, "Permission denied", 17);
		write(2, "\n", 1);
	}
	if (stat == 127)
	{
		write(2, programe_name, _strlen(programe_name));
		write(2, ": ", 2);
		write(2, "2", 1);
		write(2, ": ", 2);
		write(2, line, (int)strlen(line));
		write(2, ": ", 2);
		write(2, "not found", sizeof("not found") - 1);
		write(2, "\n", 1);
	}
}
