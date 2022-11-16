#include "main.h"

/**
 * hsh_launch - program that runs the shell
 * @args: counts commandline arguments
 * Return: 1 true
 */
int hsh_launch(char **args)
{
	pid_t pid;

	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("lsh");
	}
	else
	{
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
