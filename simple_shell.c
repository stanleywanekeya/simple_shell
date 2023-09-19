#include "simple_shell.h"
/**
 * main - Main entry point
 * @env: environment variable
 * @argc: main argument count
 * @argv: main argument array
 * Return: Always 0
 */
int main(int __attribute__((__unused__))argc,
		char __attribute__((__unused__))**argv, char **env)
{
	char *cmd_line;

	while (true)
	{
		show_prompt();
		cmd_line = get_line();
		execute(cmd_line, env);
	}
	free(cmd_line);
	return (0);
}
