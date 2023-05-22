#include "main.h"
/**
 * _strtok - Function string tokenization
 * @str: string
 * @delimiters: delimiters
 * Return: tokenize cahracter
*/
char *_strtok(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}
