#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char* hsh_read_line(void);
char** hsh_split_line(char *line);
void hsh_exec(char **args);

#endif /*main.h*/
