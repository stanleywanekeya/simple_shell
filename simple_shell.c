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
	bool is_terminal;

	(void) argc;
	(void) argv;
	is_terminal = isatty(STDIN_FILENO);
	while (true)
	{
		show_prompt();
		if (is_terminal)
		{
			cmd_line = get_line();
			if (cmd_line == NULL)
				break;
			if (strcmp(cmd_line, "\n") == 0)
			{
				free(cmd_line);
				continue;
			}
			execute(cmd_line, env);
			free(cmd_line);
		}
		else
		{
			cmd_line = get_line();
			if (cmd_line == NULL)
				break;
			execute(cmd_line, env);
			free(cmd_line);
			break;
		}
	}
	return (0);
}
