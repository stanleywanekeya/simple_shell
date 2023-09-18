#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

/**
 * test_path - finds out if the command is foud in the path
 * @path: path where command are found
 * @command: command entered by user
 * Return: command if found and NULL if not
 */
void test_path(char *path, char *command, char fullpath[])
{
	char *dir, *new;
	int i;

	i = 0;
	new = strdup(path);
	if (strchr(command, '/') == NULL)
	{
		dir = strtok(new, ":");
		while (dir)
		{
			snprintf(fullpath, 255, "%s/%s", dir, command);
			if (access(fullpath, X_OK) == 0)
			{
				return;
			}
			dir = strtok(NULL, ":");
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
		return;
	}
}
