#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* builtin shell commands */
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

/* list of builtin commands */
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit
};

int hsh_num_builtins(void);

int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

int hsh_launch(char **args);
int hsh_execute(char **args);
char *hsh_read_line(void);

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"

char **hsh_split_line(char *line);
void hsh_loop(void);

#endif
