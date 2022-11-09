#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*builtin cmd*/
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

/*builtin func*/
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

int hsh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

/*prompt & exec*/
int hsh_launch(char **args);
int main(int argc, char **argv);
void hsh_loop(void);
char **hsh_split_line(char *line);

#endif /*shell.h*/
