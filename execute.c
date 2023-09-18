#include <stdio.h>
#include "simple_shell.h"
/**
 * execute - function to execute command line
 * @line: command line to be executed
 */
void execute(char *line)
{
	pid_t child;
	char fullpath[255];
	char *arg[255];
	char *path;
	int status;

	_tokenize(line, " \n", arg, 255);
	path = getenv("PATH");
	test_path(path, arg[0], fullpath);
	if (fullpath == NULL)
	{
		fprintf(stderr, "Failed to locate path\n");
		exit(EXIT_FAILURE);
	}
	child = fork();
	if (child == -1)
	{
		fprintf(stderr, "Failed to fork\n");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(fullpath, arg, NULL) == -1)
		{
			perror("Execve\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
