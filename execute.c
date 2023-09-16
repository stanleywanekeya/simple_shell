#include <stdio.h>
#include <string.h>
#include "simple_shell.h"

/**
 * execute - function to execute command line
 * @line: command line to be executed
 */
void execute(char *line)
{
	pid_t child;
	char fullpath[255];
	char *token, *path, *dir;
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
		if (strchr(arg[0], '/') == NULL)
		{
			path = getenv("PATH");
			if (path)
			{
				dir = strtok(path, ":");
				while (dir)
				{
					snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, arg[0]);
					if (access(fullpath, X_OK) == 0)
					{
						if (execve(fullpath, arg, NULL) == -1)
						{
							perror("Execve\n");
							exit(EXIT_FAILURE);
						}
					}
					dir = strtok(NULL, ":");
				}
			}
		}
		else
		{
			if (execve(arg[0], arg, NULL) == -1)
			{
				perror("Execve\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		wait(&status);
}
