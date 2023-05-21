#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: string to be converted
*
* Return: the int converted from the string
*/
int _atoi(char *s)
{
	int i;
	int number;
	int TheGatheredNumbers = 0;
	int len = 0;
	int ThePresenceOfTheString;

	while (s[len] != '\0')
		len++;
	for (i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number = s[i] - '0';
			TheGatheredNumbers = TheGatheredNumbers * 10 + number;
			ThePresenceOfTheString = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			ThePresenceOfTheString = 0;
		}
	}
	if (ThePresenceOfTheString == 0)
		return (0);
	return (TheGatheredNumbers);
}
