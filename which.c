#include "main.h"

char *_which(char *cmd)
{
	char *tok, *s, *c, *copy;
	int len_cmd = 0, len_tok = 0;
	char *path = getenv("PATH");

	copy = strdup(cmd);
	strtok(copy, " ");
	len_cmd = (int)strlen(copy);
	if (access(copy, F_OK) == 0) 
		return (copy);
	len_cmd = (int)strlen(copy);
	tok = strtok(path, ":");
	len_tok = (int)strlen(tok);
	c = (char *)malloc(len_tok + 1);
	s = (char *)malloc(len_cmd + len_tok + 3);
	while (tok)
	{
		strcpy(c, tok);
		strcat(c, "/");
		s = strcat(c, copy);
		if (access(s, F_OK) == 0)
		{
			return (s);
		}
		tok = strtok(NULL, ":");
	}
	return (NULL);
}
