#include "shell.h"

int hsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

int hsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return 1;
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i] = 0))
		{
			return (*builtin_func[i])(args);
		}
	}

	return hsh_launch(args);
}
