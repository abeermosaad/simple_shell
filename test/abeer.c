#include "main.h"

char *_which(char *cmd)
{
	char *tok, *s, *c;
	int len_cmd = 0, len_tok = 0;
	char *path = getenv("PATH");

	len_cmd = (int)strlen(cmd); // ls
	tok = strtok(path, ":");
	len_tok = (int)strlen(tok);

	c = (char *)malloc(len_tok + 1);
	s = (char *)malloc(len_cmd + len_tok + 3);
	// c --> /usr/bin
	// strcat(c, "/");// c --> /usr/bin/
	// s = strcat(c, str);// c --> /usr/bin/ls
	// printf("%s\n", s);
	while (tok)
	{
		strcpy(c, tok);
		strcat(c, "/");
		s = strcat(c, cmd);
		if (access(s, X_OK) == 0)
		{
			return (s);
		}
		tok = strtok(NULL, ":");
	};
}
