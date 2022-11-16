#include "main.h"

/**
 * hsh_loop - function that makes user
 * stay in the shell by calling running function
 */
void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	} while (status);
}
