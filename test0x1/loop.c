#include "main.h"

/**
 * main - display prompt and read user input
 * Return: always 0
 */

int main(void)
{
	while (true)
	{
		printf("$ ");
		char *line = hsh_read_line();
		char **tokens = hsh_split_line(line);

		if (tokens[0] != NULL)
		{
			hsh_exec(tokens);
		}

		free(tokens);
		free(line);
	}
}
