#include "main.h"

void excute_notFound (char *line, char **cmd_argv, char *environment[], int *status)
{
	int exc;
	int id;
	pid_t terminatedChildPid;

	id = fork();
	if (id == -1)
		perror("ERROR IN FORK");
	if (id == 0)
	{
		
		exc = execve(line, cmd_argv, environment); /// /bin 126 
		if (exc == -1)
		{
			exit(127);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		*status = WEXITSTATUS(*status);
	}
}