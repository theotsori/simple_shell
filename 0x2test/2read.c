#include "main.h"

/**
 * hsh_read_line - reads commandline for arguments
 * Return: line
 */
char *hsh_read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
