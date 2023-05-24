#include "main.h"
/**
 * handle_new_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line(\n)
*/
char *handle_new_line(char *line)
{
	int len, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = (int)_strlen(line);
	if (len == 1 && line[0] == '\n')
	{
		return (line);
	}
	len = (int)_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
/**
 * is_excutable - Function that check if the cmd is excutable or not
 * @line: Take the line from getline function
 * Return: The command
*/
char *is_excutable(char *line)
{
	char *tok, *line_copy, *path_copy, *path, *str;
	int len_command = 0, len_tok = 0;

	path = _getenv("PATH");
	path_copy = _strdup(path);
	line_copy = _strdup(line);
	_strtok(line_copy, TOK_DELIM);
	if ((access(line_copy, F_OK) == 0) && ((line_copy[0] == '/') ||
	(line_copy[1] == '/') || (line_copy[2] == '/')))
	{
		free(path_copy);
		return (line_copy);
	}
	len_command = (int)_strlen(line_copy);
	tok = _strtok(path_copy, ":");
	len_tok = (int)_strlen(tok);
	while (tok)
	{
		str = malloc(len_command + len_tok + 2);
		_strcpy(str, tok);
		_strcat(str, "/");
		_strcat(str, line_copy);
		if (access(str, F_OK) == 0)
		{
			free(line_copy);
			free(path_copy);
			return (str);
		}
		free(str);
		tok = _strtok(NULL, ":");
		if (!tok)
		{
			free(line_copy);
			free(path_copy);
			break;
		}
		len_tok = (int)_strlen(tok);
	}
	return (NULL);
}
