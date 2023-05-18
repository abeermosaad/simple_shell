#include "main.h"

char *handle_new_line(char *line)
{
	int len;

	len = (int)strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char *is_excutable(char *line)
{
	char *tok, *line_copy, *path_copy, *path, *str;
	int len_command = 0, len_tok = 0;

	path = getenv("PATH"); // _getenv
	path_copy = strdup(path);

	line_copy = strdup(line);

	_strtok(line_copy, " ");

	line_copy = handle_new_line(line_copy);

	if (access(line_copy, F_OK) == 0)
		return line_copy;

	len_command = (int)strlen(line_copy);
	tok = _strtok(path_copy, ":");
	len_tok = (int)strlen(tok);

	while (tok)
	{
		str = malloc(len_command + len_tok + 2);
		strcpy(str, tok);
		strcat(str, "/");
		strcat(str, line_copy);

		if (access(str, F_OK) == 0)
			return str;

		free(str);
		tok = _strtok(NULL, ":");
		len_tok = (int)strlen(tok);
	}
	return (NULL);
}


