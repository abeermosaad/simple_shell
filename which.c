#include "main.h"

char *_which(char *cmd)
{
	char *tok, *s, *c, *copy, *copy2;
	int len_cmd = 0, len_tok = 0;
	char *pa = getenv("PATH");
	char *path = strdup(pa);

	copy = strdup(cmd);
	strtok(copy, " ");
	if (copy[strlen(copy) - 1] == '\n')
		copy[strlen(copy) - 1] = '\0';
	len_cmd = (int)strlen(copy);
	if (access(copy, F_OK) == 0)
		return (copy);
		
	tok = strtok(path, ":");
	len_tok = (int)strlen(tok);
	s = (char *)malloc(len_cmd + len_tok + 2);
	while (tok)
	{
		strcpy(s, tok);
		strcat(s, "/");
		s = strcat(s, copy);
		if (access(s, F_OK) == 0)
			return (s);
		free(s);
		tok = strtok(NULL, ":");
		len_tok = (int)strlen(tok);
		s = (char *)malloc(len_cmd + len_tok + 2);
	}
	return (NULL);
}
