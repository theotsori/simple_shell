#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void hsh_loop(void);
char *hsh_read_line(void);
int hsh_execute(char **args);
int hsh_launch(char **args);
char **hsh_split_line(char *line);
int hsh_num_builtins(void);

#endif /*main.h*/
