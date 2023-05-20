#ifndef MAIN_H
#define MAIN_H
#define TOK_DELIM " \t\r\n\a\""
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void _env(char **env);
int ex(char *line);
int _atoi(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _strcat(char *str1, const char *str2);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *is_excutable(char * cmd);
char *handle_new_line(char *line);
char* _getenv(char* input);
void excute(char *command, char **argv, char *env[]);
void is_builtin(char *line, char **env);
char **generate_argv(char *line);
char *_strtok(char *str, const char *delimiters);
#endif
