#include "main.h"

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"

/**
 * hsh_split_line - function that makes the shell run
 * @line: reads what is typed by user
 * Return: space allocated to shell
 */
char **hsh_split_line(char *line)
{
	int bufsize = HSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, HSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += HSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, HSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
