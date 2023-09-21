#include "simple_shell.h"
/**
 * execute - function to execute command line
 * @environ: environment variable acquired through main
 * @line: command line to be executed
 */
void execute(char *line, char **environ)
{
	pid_t child;
	char fullpath[255], *arg[255], *path;
	int status;

	_tokenize(line, " \n", arg, 255);
	path = getenv("PATH");
	if (_strcmp(line, "exit") == 0)
	{
		free(line);
		exit_cmd();
	}
	if (_strcmp(line, "env") == 0)
		_env(environ);
	if (strncmp(line, "cd", 2) == 0)
	{
		cd(arg[1]);
	}
	else
	{
		test_path(path, arg[0], fullpath);
		if (fullpath == NULL)
		{
			perror("Failed to locate path\n");
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
}
