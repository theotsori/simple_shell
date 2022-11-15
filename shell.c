#include "main.h"

/**
 *
 */
int hsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *
 */
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

/**
 *
 */
int hsh_help(__attribute__((unused))char **args)
{
	int i;

	printf("Theodore & Luke Shell\n");
	printf("Type commndline arguments, and press enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for more information.\n");
	return (1);
}

/**
 *
 */
int hsh_exit(__attribute__((unused))char **args)
{
	return (0);
}
