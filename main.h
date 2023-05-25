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
/*env command*/
void _env(void);
char *_getenv(char *name);
extern char **environ;
int setenv_builtin(const char *name, const char *value);
/*exit command*/
int ex(char *line, int *stat, int count, char *programe, char *ml);
/*Handeled functions*/
char *_strdup(char *str);
void _strcat(char *str1, const char *str2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *print_number(int n);
/*Advanced functions*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delimiters);
/*Excution commands*/
char *handle_new_line(char *line);
int is_builtin(char *programe, char *line, int *status, int count, char *ml);
char *is_excutable(char *cmd);
char **generate_argv(char *line);
int excute(char *command, char **argv, char *env[], int *status);
void excute_notFound(char *line, char **cmd_argv,
char *environment[], int *status);
/*non,interactive modes*/
void non_interactive(char **argv);
void interactive(char **argv);
/*Errors*/
void print_error(char *argv, int count, int stat, char *line);
void exit_error(char *programe_name, char *counter, char *line);
void command_error(char *programe_name, char *counter, char *line);
void path_error(char *programe_name, char *counter, char *line);
#endif
