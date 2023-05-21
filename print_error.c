#include "main.h"
/**
 * ex - Function that exit
 * @line: From user
 * Return: status
*/
void print_error(char *programe_name, int count, int stat)//126
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
}
