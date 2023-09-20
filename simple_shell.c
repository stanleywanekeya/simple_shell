#include "simple_shell.h"
/**
 * main - Main entry point
 * @env: environment variable
 * @argc: main argument count
 * @argv: main argument array
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *cmd_line;

	(void) argc;
	(void) argv;
	while (true)
	{
		show_prompt();
		cmd_line = get_line();
		execute(cmd_line, env);
	}
	free(cmd_line);
	return (0);
}
