#include <stdio.h>
#include "simple_shell.h"

/**
 * execute - function to execute command line
 * @line: command line to be executed
 */
void execute(char *line)
{
	pid_t child;
	char *token;
	char *arg[255];
	int count, status;

	count = 0;
	child = fork();
	if (child == -1)
	{
		fprintf(stderr, "Failed to fork\n");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		token = strtok(line, " \n");
		while (token != NULL)
		{
			arg[count] = token;
			token = strtok(NULL, " \n");
			++count;
		}
		arg[count] = NULL;
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("Execve\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
