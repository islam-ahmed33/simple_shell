#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @nmbr: the number field
 * @stng: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int nmbr;
	char *stng;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT                                                            \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}


/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* errors.c - 100% */
void eputs_Iso(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* exits.c - 100% */
char *strncpy_Iso(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* realloc.c - 100% */
char *st_mm(char *, char, unsigned int);
void f_mp(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* string.c - 100% */
int str_lngth(char *);
int str_com(char *, char *);
char *stw_Iso(const char *, const char *);
char *str_conc(char *, char *);

/* atoi.c - 100% */
int Iso(info_t *);
int d_islem(char, char *);
int isalpha(int);
int _atoi(char *);

/* builtin.c - 100% */
int myexit(info_t *);
int _mycd(info_t *);
int myhelp(info_t *);

/* builtin1.c - 100% */
int myhistory_Iso(info_t *);
int _myalias(info_t *);
int unset_alias_Iso(info_t *info, char *str);
int set_alias_maati(info_t *info, char *str);
int print_alias(list_t *node);

/* environ.c  - 100% */
char *getenv_Iso(info_t *, const char *);
int myenv_Iso(info_t *);
int mysetenv_Iso(info_t *info);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* errors1.c - 100% */
int erratoi_Iso(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

#endif
