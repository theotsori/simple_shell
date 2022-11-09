#include "shell.h"

char *hsh_read_line(void)
{
#ifdef HSH_USE_STD_GETLINE
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We received an EOF
    } else  {
      perror("hsh: getline\n");
      exit(EXIT_FAILURE);
    }
  }
  return line;
#else
#define HSH_RL_BUFSIZE 1024
  int bufsize = HSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "hsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    if (c == EOF) {
      exit(EXIT_SUCCESS);
    } else if (c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += HSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "hsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
#endif
}

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"


char **hsh_split_line(char *line)
{
	int bufsize = HSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

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
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));

			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, HSH_TOK_DELIM);
	}

	tokens[position] = NULL;
	return tokens;
}

void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("$ ");
		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	}
	while (status);
}

int main(int argc, char **argv)
{
	hsh_loop();
	return EXIT_SUCCESS;
}
