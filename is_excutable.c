#include "main.h"
/**
 * handle_new_line - Function handles the line that user enters
 * @line: take the line from getline function
 * Return: handled string without new line
*/
char *handle_new_line(char *line)
{
	int len;

	len = (int)_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char *is_excutable(char *line)
{
	char *tok, *line_copy, *path_copy, *path, *str;
	int len_command = 0, len_tok = 0;

	path = getenv("PATH"); // _getenv
	path_copy = strdup(path);// _strdup

	line_copy = strdup(line);

	_strtok(line_copy, " ");

	line_copy = handle_new_line(line_copy);

	if (access(line_copy, F_OK) == 0)
		return (line_copy);

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
			return (str);

		free(str);
		tok = _strtok(NULL, ":");
		len_tok = (int)_strlen(tok);
	}
	return (NULL);
}
