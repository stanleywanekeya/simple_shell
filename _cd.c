#include "simple_shell.h"

/**
 * cd - changes directory
 * @dir: the path to change to
 */
void cd(char *dir)
{
	char *path;

	path = getenv("HOME");
	if (path == NULL)
		exit(EXIT_FAILURE);
	if (dir == NULL)
		chdir(path);
	else
		chdir(dir);

}
