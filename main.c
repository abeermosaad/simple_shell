#include "main.h"
/**
 * main - Function that run SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * @env: The shell environment
 * Return: 
*/
int main()
{
	char* line = NULL;
	// char **argv;
	// char *env[] = {NULL};
	char *s;
	size_t len = 0;
	ssize_t read;

	if(isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, ":) ", sizeof(":) ") - 1);
			read = getline(&line, &len, stdin);
			if (read == -1)  
				break;
			// if(built_in(line))
			// {
			// 	//do some coding
			// }
			
			if((s = _which(line)) != NULL) 
			{
				// s = _which(line);// ls -l
				// printf("%ld\n",strlen(s));
				// printf("%s\n", s);
				_excute(s, line);
				// printf("%s\n", s);
			}
		}
		free(line);
	}
	return (0);
}
