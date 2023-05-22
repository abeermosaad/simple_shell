#ifndef MAIN_H
#define MAIN_H
#define TOK_DELIM " \t\r\n\a\""
#define CmdNOT_FOUND 127
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void excute_notFound (char *line, char **cmd_argv, char *environment[], int *status);
char *print_number(int n);
void print_error(char *argv, int count, int stat, char *line);
void _env(char **env);
int ex(char *line, int *stat, int count, char *programe);
int _atoi(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _strcat(char *str1, const char *str2);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *is_excutable(char * cmd);
char *handle_new_line(char *line);
char* _getenv(char* input);
int excute(char *command, char **argv, char *env[], int *status);
int is_builtin(char *programe, char *line, char **env, int *status, int count);
char **generate_argv(char *line);
char *_strtok(char *str, const char *delimiters);
#endif
