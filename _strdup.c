#include "simple_shell.h"

char *_strdup(char *str)
{
	char *new;
	size_t i, len;

	i = len = 0;
	if (str == NULL)
	{
		perror("No string to duplicate\n");
		exit(EXIT_FAILURE);
	}
	while (str[len])
		++len;
	new = (char *)malloc((len + 1) * sizeof(char));
	while (str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
