#include "main.h"
/**
 * print_error - Function that print error
 * @programe_name: Programe_name
 * @count: Count commands
 * @stat: Stat of process
 * @line: The line
 * Return: .
*/
void print_error(char *programe_name, int count, int stat, char *line)
{
	char *counter;

	counter = print_number(count);
	if (stat == 126)
		path_error(programe_name, counter, line);
	if (stat == 127)
		command_error(programe_name, counter, line);
	if (stat == 2 && (strncmp(line, "exit", 4) == 0))
		exit_error(programe_name, counter, line);
	free(counter);
}
/**
 * path_error - Function that print error
 * @programe_name: Programe_name
 * @counter: Count commands
 * @line: The line
 * Return: .
*/
void path_error(char *programe_name, char *counter, char *line)
{
	write(2, programe_name, _strlen(programe_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, line, (int)strlen(line));
	write(2, ": ", 2);
	write(2, "Permission denied", sizeof("Permission denied") - 1);
	write(2, "\n", 1);
}
/**
 * command_error - Function that print error
 * @programe_name: Programe_name
 * @counter: Count commands
 * @line: The line
 * Return: .
*/
void command_error(char *programe_name, char *counter, char *line)
{
	write(2, programe_name, _strlen(programe_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, line, (int)strlen(line));
	write(2, ": ", 2);
	write(2, "not found", sizeof("not found") - 1);
	write(2, "\n", 1);
}
/**
 * exit_error - Function that print error
 * @programe_name: Programe_name
 * @counter: Count commands
 * @line: The line
 * Return: .
*/
void exit_error(char *programe_name, char *counter, char *line)
{
	char *token;

	strtok(line, TOK_DELIM);
	write(2, programe_name, _strlen(programe_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, line, (int)strlen(line));
	write(2, ": ", 2);
	write(2, "Illegal number", sizeof("Illegal number:") - 1);
	write(2, ": ", 2);
	token = strtok(NULL, TOK_DELIM);
	write(2, token, (int)strlen(token));
	write(2, "\n", 1);
}
/**
 * print_number - number to string
 *
 * @n: params an integer
 *
 * Return: number to string
 */

char *print_number(int n)
{
	unsigned int d, count;
	int length = 0, i = 0;
	char *counter;

	d = n;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
		length++;
	}
	length++;
	counter = (char *)malloc(length + 1);
	if (counter == NULL)
		return (NULL);
	for (; count >= 1; count /= 10)
	{
		counter[i++] = ((n / count) % 10) + '0';
	}
	counter[length] = '\0';
	return (counter);
}
