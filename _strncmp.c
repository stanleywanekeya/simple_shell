#include "simple_shell.h"

/**
 * _strncmp - compares two strings
 * @s1: string argument to be compared
 * @s2: string argument to be compared
 * @n: number of times to compare sttrings
 * Return: value when two strings are compared
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}
