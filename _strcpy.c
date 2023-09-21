#include "simple_shell.h"

char *_strcpy(char *dest, char *src)
{
	size_t i, len;

	i = len = 0;
	while (src[len])
	{
		++len;
	}
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
