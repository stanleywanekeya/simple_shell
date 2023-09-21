#include "simple_shell.h"

char *_getenv(const char *path)
{
	char *name, *value;
	int i;
	if (!path)
	{
		perror("Execve\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; 

}
