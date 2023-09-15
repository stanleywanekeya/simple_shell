#include "simple_shell.h"
/**
 * main - Main entry point
 * Return: Always 0
 */
int main(void)
{
	char *cmd_line;
	while(true)
	{
		show_prompt();
		cmd_line = get_line();
		execute(cmd_line);
	}
	return (0);
}
