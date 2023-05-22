#include "main.h"
/**
 * _getline - Function that check built ins
 * @lineptr: pointer to string
 * @n: bufeer
 * @stream: stream
 * Return: read count
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
