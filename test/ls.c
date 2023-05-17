#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
/*Prototypes*/
int _strlen(char *s);
void _ls(char *path);
/*Entry point*/
int main()
{
	char *currentdirectory;

	currentdirectory = "/usr/bin";
	_ls(currentdirectory);
	return 0;
}
/*which command*/
void _ls(char *path)
{
	DIR *currentdirectory;//DIR Type
	struct dirent *dirptr;//point to the entry dir//

	currentdirectory = opendir(path);//fails return NULL//open dir
	if (!currentdirectory)
	{
		perror("ERROR in openning directory");
	}

	dirptr = readdir(currentdirectory);//END return NULL//read what is inside it
	while (dirptr)
	{
		write(STDOUT_FILENO, dirptr->d_name, _strlen(dirptr->d_name));//dirptr->d_name name of file
		write(STDOUT_FILENO, "\n", 1);
		dirptr = readdir(currentdirectory);//go to the next one
	}
	closedir(currentdirectory);
}
/*STRLEN*/
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
