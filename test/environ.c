#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char** environ; // Declaration of the environ variable
char *_getenv(const char *name);
int _strcmp(char *s1, const char *s2)
{
	int i = 0;
	int result = 0;
	
	for (i = 0; ((s1[i] != '\0') && (s2[i] != '\0')); i++)
	{
		result = (s1[i] - s2[i]);
		if (result != 0)
		{
			return (result);
		}
	}
	return (0);
}
int main()
{
	char *value = "SHELL";
	char *str;
	int i = 0;

	str = _getenv(value);
	// while (environ[i])
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// } 
	printf("%s\n", str);
	return (0);
}
char *_getenv(const char *name)
{
	// Accessing the environment variables
	char** env = environ;//array of strings terminated by a NULL pointer//environ<-->env
	char *token;
	int i = 0;
	int len;

	while (*env != NULL)
	{
		token = strtok(*env, "=");//first part before "="//HOME\0/root\0
		if (strcmp(token, name) == 0)
		{
			while (token) // HOME\0
			{
				token = strtok(NULL, "=");//HOME\0-->/root the remaining part
				if (token)
				{
					return (token); // /root
				}
				//if you want to modify yo will need to use env argument in the main function
			}
		}
		env++;
	}
	return (NULL);
}
