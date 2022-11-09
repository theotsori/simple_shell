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

struct builtin {
	char *name;
	void (*func)(char **args);
};

struct builtin builtins[] = {
	{"help", hsh_help},
	{"exit", hsh_exit},
	{"cd", hsh_cd},
};

int hsh_num_builtins();

/*loop & execv*/
char* hsh_read_line();
char** hsh_split_line(char *line);
void hsh_exec(char **args);

#endif /*main.h*/
