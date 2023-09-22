#include "simple_shell.h"

/**
 * _tokenize - tokenizes the command line
 * @line: line to be tokenized
 * Return: character tokenized
 */
char **_tokenize(char *line)
{
	char *token, *tmp, **command;
	int count, i;

	token = NULL;
	tmp = NULL;
	command = NULL;
	count = i = 0;
	tmp = _strdup(line);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(line);
		free(tmp);
		tmp = line = NULL;
		return (NULL);
	}
	while (token)
	{
		++count;
		token = strtok(NULL, " \t\n");
	}
	free(tmp);
	tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, " \t\n");
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		++i;
	}
	free(line);
	line = NULL;
	return (command);
}
