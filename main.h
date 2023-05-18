#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *is_excutable(char * cmd);
char *handle_new_line(char *line);
char* _getenv(char* input);
void excute(char *command, char **argv, char *env[]);
int is_builtin(char *line);
char **generate_argv(char *line);
char *_strtok(char *str, const char *delimiters);
#endif
