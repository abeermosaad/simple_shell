#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[] = "Linux Way Again";
	/*char d[] = " ";
	char *portion;*/

	int i = 0;
	int start = 0;

	/*portion = strtok(s, d);
	while (portion)
	{
		printf("%s", portion);
		portion = strtok(NULL, d);
	}
	printf("\n");*/

	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			s[i] = '\0';
			printf("%s\n", s + start);
			start = i + 1;
		}
		printf("i = %d, start = %d\n", i, start);
		i++;
	}
	printf("i = %d, start = %d\n", i, start);
	if (start < i)
		printf("%s\n", &s[start]);
	return (0);
}
