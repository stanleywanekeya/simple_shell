#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

/**
 * test_path - finds out if the command is found in the path
 * @path: path where command are found
 * @command: command entered by user
 * @fullpath: buffer to store the path
 * Return: command if found and NULL if not
 */
void test_path(char *path, char *command, char fullpath[])
{
	char *dir, *new;
	int i;

	i = 0;
	new = _strdup(path);
	if (new == NULL)
	{
		perror("Failed to duplicate new\n");
		exit(EXIT_FAILURE);
	}
	if (_strchr(command, '/') == NULL)
	{

		dir = strtok(new, ":");
		while (dir)
		{
			_strcpy(fullpath, dir);
			_strcat(fullpath, "/");
			_strcat(fullpath, command);
			if (access(fullpath, X_OK) == 0)
			{
				free(new);
				return;
			}
			dir = strtok(NULL, ":");
			memset(fullpath, 0, 255);
		}
	}
	else
	{
		if (access(command, X_OK) == 0)
		{
			while (*command)
			{
				fullpath[i] = *command;
				++command;
				++i;
			}
			fullpath[i] = '\0';
		}
		free(new);
		return;
	}
}
