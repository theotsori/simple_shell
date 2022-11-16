#include "main.h"

int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit
};

/**
 * hsh_num_builtins - allocates memory for builtins in string
 * Return: builtins
 */
int hsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * hsh_cd - calls the cd function.
 * @args: no of cmd line argument passed
 * Return: 1 if true
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
 * hsh_help - help builtin func
 * @args: no of cmd line arguments
 * Return: 1 true
 */
int hsh_help(__attribute__((unused))char **args)
{
	int i;

	printf("Luke & Theodore Shell\n");
	printf("Type commandline arguments, and press Enter.\n");
	printf("Available builtins:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("for information on other programs, use Man command.\n");
	return (1);
}

/**
 * hsh_exit - used to exit program
 * @args: no of cmd line arguments
 * Return: 1 true
 */
int hsh_exit(__attribute__((unused))char **args)
{
	return (0);
}

/**
 * hsh_execute - function executes programs that runs the shell
 * @args: no of cmd line arguments
 * Return: 1 true
 */
int hsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (hsh_launch(args));
}
