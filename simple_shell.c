#include "simple_shell.h"
/**
 * main - Main entry point
 * Return: Always 0
 */
int main(void)
{
	char input[150];

	while (true)
	{
		show_prompt();
		read_input(input, sizeof(input));
		execute(input);
	}
	return (0);
}
