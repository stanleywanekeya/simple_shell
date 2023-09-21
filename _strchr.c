#include "simple_shell.h"

char *_strchr(const char *path, int c)
{
	size_t i;

	if (path == NULL)
	{
		perror("No search path\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; path[i] != c; ++i)
	{
		if (path[i] == '\0')
			return (NULL);

	}
	return (char*)(path + i);
}
