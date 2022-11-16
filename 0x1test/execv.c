#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *newArgv[] = { NULL, "Hey", "There", "Theodore", NULL };
	char *newEnviron[] = { NULL };

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	newArgv[0] = argv[1];

	execve(argv[1], newArgv, newEnviron);
	perror("execve");
	exit (EXIT_SUCCESS);
}
