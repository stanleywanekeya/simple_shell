#include "simple_shell.h"

/**
 * _env - prints environment variables
 * @environ: environment variable
 */
void _env(char **environ)
{
	char **env;
	int i;

	i = 0;
	for (env = environ; env[i]; ++i)
		printf("%s\n", env[i]);
}
