#include "simple_shell.h"
/**
 * main - Main entry point
 * @env: environment variable
 * @argc: main argument count (unused)
 * @argv: main argument array (unused)
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
		if (cmd_line == NULL)
			break;
		if (strcmp(cmd_line, "exit") == 0)
		{
			free(cmd_line);
			break;
		}
		if (strcmp(cmd_line, "quit") == 0)
		{
			free(cmd_line);
			break;
		}

		execute(cmd_line, env);
	}
	free(cmd_line);
	return (0);
}
