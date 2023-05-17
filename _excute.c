#include "main.h"

void _excute(char *cmd, char *line)
{
	char **argv;
	int exc;
	char *env[] = {NULL};
	char *command;
	int i = 0, id;

	// printf("%s", cmd);//----->The problem in ls only
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	argv = malloc(strlen(line) + 1);
	if (!argv)
	{
		perror("malloc");
	}

	command = strtok(line, " "); // /bin/ls -l
	while (command) 
	{
		argv[i] = command;
		command = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;	


	id = fork();
	// printf("%d\n", id);
	if (id == -1)
	{
		perror("ERROR IN FORK");
	}
	if (id == 0)
	{
		// for (i = 0; argv[i] != NULL; i++)
		// {
		// 	printf("%s\n", argv[i]);
		// 	fflush(stdout);
		// }
		exc = execve(cmd, argv, env);
		if (exc == -1)
		{
			perror("ERROR IN EXCEUTE");
		}
	}
	else
	{
		wait(NULL);
	}
}
