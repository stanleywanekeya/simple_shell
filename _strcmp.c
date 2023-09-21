#include "simple_shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string argument to be compared
 * @s2: string argument to be compared
 * Return: value when two strings are compared
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}
