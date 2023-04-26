#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int excute(char **, char **);
int _getline(char **line);
char *get_location(char *command);
char *read_command(int *);
char **split_command(char *, int *);
char **_get_env( char *var);
ssize_t _getline(char **line);

void handler(int);
int shell_env(char **);
int shell_exit(char **);
int shell_cd(char **);
int shell_cd(char **);
list_s *_get_env_value(char *variable)

int _strlen(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *,int);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(char *);

#endif
