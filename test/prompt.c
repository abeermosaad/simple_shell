#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char* line = NULL;
	char **argv;
	char *env[] = {NULL};
	char *command;
	char *arguments;
	size_t len = 0;
	ssize_t read;
	while (1)
	{
		write(1, ":) ", sizeof(":) ") - 1);
		read = getline(&line, &len, stdin);/*ssize_t getline(char** lineptr, size_t* n, FILE* stream);*/
		/*if i want to make get line i will use read and write and the buffer that i read and stream file input file*/
		if (read == -1) // ctrl+d --> -1 = EOF; 
			break;
		argv = malloc(strlen(line) + 1); // /bin/ls -la 11
		command = strtok(line, " "); // /bin/ls 
		printf("%s\n", command);
		command[read - 1] = '\0';
		arguments = strtok(NULL, " ");
		argv[0] = command;
		argv[1] = arguments;
		argv[2] = NULL;

		int id = fork();
		if (id == -1)
		{
			perror("ERROR IN FORK");
		}
		if (id == 0)
		{
			int exc = execve(argv[0], argv, env);
			if (exc == -1)
		{
		perror("ERROR IN EXCEUTE");
		}
		}
		else
		wait(NULL);

		//"/bin/ls -al" --> char **str = malloc(strlen(line))
		//"/bin/ls -l"--> strtok() -->[ls\0-la\0] ==> str[0]=>/bin/ls str[1]=>-l..........printf("%s", str[1])-->ls-la;
		// excve(str[0], char *argv[]= {str[0],str[1],NULL}, NULL);
	}
	free(line);
	return (0);
}
