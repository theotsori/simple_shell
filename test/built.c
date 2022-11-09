#include "shell.h"

int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}

	return (1);
}

int hsh_help(char **args)
{
	int i;
	printf("Luke & Theodore C shell\n");
	printf("Type commands and arguments then Enter.\n");
	printf("The following commands are builtins:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}

	printf("Use man command for more information.\n");
	return 1;
}

int hsh_exit(char **args)
{
	return (0);
}
