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

	if (isatty(STDIN_FILENO))
		show_prompt();
	n = nread = 0;
	nread = getline(&line, &n, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
