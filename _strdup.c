#include "simple_shell.h"

/**
 * _strdup - duplicates memory
 * @str: string to duplicate
 * Return: value duplicated
 */
char *_strdup(char *str)
{
	char *new;
	size_t i, len;

	i = len = 0;
	if (str == NULL)
	{
		perror("No string to duplicate\n");
		return (NULL);
	}
	while (str[len])
		++len;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
	{
		perror("Failed to allocate memory\n");
		return (NULL);
	}
	while (str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
