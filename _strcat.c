#include "simple_shell.h"

char *_strcat(char *dest, char *src)
{
	size_t i, len;

	len = i = 0;
	while (dest[len])
		++len;
	while (src[i])
	{
		dest[len] = src[i];
		++len;
		++i;
	}
	dest[len] = '\0';
	return (dest);
}
