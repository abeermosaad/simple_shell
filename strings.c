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
	size_t len2 = strlen(str2);
	size_t i = 0;

	while (str2[i])
	{
		str1[len1 + i] = str2[i];
		i++;
	}

	str1[len1 + i] = '\0';
}
/**
 * _strdup - Function that copy
 * @str1: first string
 * @str2: Second String
*/
