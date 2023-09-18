#include "simple_shell.h"
/**
 * _strlen - cutom function to calculate string length
 * @string: Pointer to string
 * Return: length of string
 */

size_t _strlen(const char *string)
{
	size_t len = 0;

	while (string[len] != '\0')
	{
		len += 1;
	}
	return (len);
}
