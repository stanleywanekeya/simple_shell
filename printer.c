#include "simple_shell.h"
/**
 * printer -  function that prints input from user
 * @input: Pointer to the user input to be printed
 * Return: Always 0
 *
 */
void printer(const char *input)
{
	write(STDOUT_FILENO, input, _strlen(input));
}
