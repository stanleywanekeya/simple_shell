#include "simple_shell.h"

/**
 * get_line - gets line from command line
 * Return:  line obtsined from command line
 */
char *get_line(void)
{
	char *line;
	ssize_t nread;
	size_t n;

	n = nread = 0;
	nread = getline(&line, &n, stdin);
	return (line);
}
