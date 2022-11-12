#include "main.h"

/**
 * hsh_exec - function that runs prompt on cmdline
 * @args: cmd arguments
 *
 * Return: 0
 */
void hsh_exec(char **args)
{
	for (int i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
/*exec that runs code*/
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("hsh");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;
		do
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("hsh");
	}
}
