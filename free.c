#include "simple_shell.h"

/**
 * freeblock - frees block of array
 * @array: array argument
 */
void freeblock(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; ++i)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
