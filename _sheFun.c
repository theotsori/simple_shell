#include "main.h"

void hsh_exit(char **args)
{
	exit(0);
}

void hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh: cd");
		}
	}
}

void hsh_help(char **args)
{
	int i;	
	printf("hsh - Luke & Theodore simple C shell. ");
	printf("Type programnames and arguments, hit Enter.\n");
	printf("The following commands are available:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf(" %s\n", builtins[i]);
	}

	printf("Use the man command for more info on other programs");
	return;
}

int hsh_num_builtins()
{
	return sizeof(builtins) / sizeof(struct builtin);
}
