#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
void hsh_exit(char **args);
void hsh_cd(char **args);
void hsh_help(char **args);
void hsh_exec(char **args);

/**
 * struct builtin - struct func for cmd line args
 * @name: char varaible
 * @func: cmd arg
 */
struct builtin
{
	char *name;
	void (*func)(char **args);
};

/**
 * struct builtin - string func for cmd builtin commands
 * @builtins: string
 */
struct builtin builtins[] = {

	{"help", hsh_help},
	{"exit", hsh_exit},
	{"cd", hsh_cd}
};

int hsh_num_builtins(void);

/*loop & execv*/
char *hsh_read_line(void);
char **hsh_split_line(char *line);
void hsh_exec(char **args);

#endif /*main.h*/
