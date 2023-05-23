#include "main.h"
/**
 * _strlen - find the length of a string
 * @s: pointer to the string to check
 * Return: Length of string
*/
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
/**
 * *_strcpy -  copies the string pointed to by src
 * @dest: char type string
 * @src: char type string
 * Description: Copy the string pointed to by pointer `src` to
 * the buffer pointed to by `dest`
 * Return: Pointer to `dest`
 */
char *_strcpy(char *dest, char *src)
{
	int index = -1;

	index++;
	while (*(src + index) != '\0')
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}
/**
 * _strcat - Function that copy
 * @str1: first string
 * @str2: Second String
*/
void _strcat(char *str1, const char *str2)
{
	size_t len1 = strlen(str1);
	size_t i = 0;

	while (str2[i])
	{
		str1[len1 + i] = str2[i];
		i++;
	}

	str1[len1 + i] = '\0';
}
/**
*_strdup - returns a pointer to a newly allocated space in memory
*@str: string to be duplicated
*Return: pointer to a new string which is a duplicate of the string str
*/
char *_strdup(char *str)
{
	char *t;
	unsigned int j;
	unsigned int size;

	if (str == NULL)
		return (NULL);

	size = strlen(str);

	t = (char *)malloc(size + 1);

	if (t == NULL)
		return (NULL);

	for (j = 0; j <= size; j++)
		t[j] = str[j];

	return (t);
}
/**
 * _strcmp -  function that compares two strings.
 * @s1:string1 to compare.
 * @s2: string two to compare.
 * Return: 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int result = 0;
	int len1, len2;

	len1 = (int)strlen(s1);
	len2 = (int)strlen(s2);

	if (len1 != len2)
		return (-1);

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
