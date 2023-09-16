#include "simple_shell.h"

/**
 * _tokenize - tokenizes the command line
 * @line: line to be tokenized
 * @delim: delimiters for the token
 * @arg: array to store the tokens
 * @max_token: maximum tokens rewuired for arg
 */
void _tokenize(char *line, const char *delim, char *arg[], int max_token)
{
	char *token;
	int count;

	count = 0;
	token = strtok(line, delim);
	while (token != NULL && count < max_token)
	{
		arg[count] = token;
		if (arg[count] == NULL)
		{
			fprintf(stderr, "Failed to alocate memory\n");
			exit(EXIT_FAILURE);
		}
		++count;
		token = strtok(NULL, delim);
	}
	arg[count] = NULL;
}
