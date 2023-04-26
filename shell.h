#ifndef SHELL_H
#define SHELL_H
#define delim " \n"
#define environ __environ

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <signal.h>


void display(char *);
char *read_command(int *);
char *get_location(char *command);
char **split_command(char *, int *);
int _getline(char **line);
int excute(char **, char **);


void handler(int);
int shell_cd(char **);
int shell_env(char **);
int shell_exit(char **);


int _strlen(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
char *_strncpy(char *, char *, int);


#endif
