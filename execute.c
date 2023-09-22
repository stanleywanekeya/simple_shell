#include "simple_shell.h"
/**
 * execute - function to execute command line
 * @command: environment variable acquired through main
 * @argv: command line to be executed
 * Return: value
 */
int execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == 1)
		{
			perror(argv[0]);
			freeblock(command);
			exit(100);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freeblock(command);
	}
	return (WEXITSTATUS(status));
}
