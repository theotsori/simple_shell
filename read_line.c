#include "main.h"

#define HSH_RL_BUFSIZE 1024
/**
 * hsh_read_line - function that reads what the user
 * has written on the command line
 * Return: buffer
 */
char *hsh_read_line(void)
{
	int bufsize = HSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += HSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);

			if (!buffer)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
