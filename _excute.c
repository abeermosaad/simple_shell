#include "main.h"

void _excute(char *cmd, char *line)
{
	char **argv;
	char *env[] = {NULL};
	char *command;
	int i = 0, id;

	// argv = malloc(strlen(line) + 1);

	command = strtok(line, " "); // /bin/ls -l
	command[strlen(command)] = '\0';
	while (command != NULL) 
	{
		argv[i] = command;
		command = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;	
	id = fork();
	if (id == -1)
	{
		perror("ERROR IN FORK");
	}
	if (id == 0)
	{
		int exc = execve(cmd, argv, env);
		if (exc == -1)
		{
			perror("ERROR IN EXCEUTE");
		}
	}
	else
	wait(NULL);
	free(line);
}