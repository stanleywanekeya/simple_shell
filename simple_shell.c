#include "simple_shell.h"
/**
 * main - Main entry point
 * @argc: main argument count
 * @argv: main argument array
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *cmd_line;
	char **command;
	int status;

	status = 0;
	cmd_line = NULL;
	command = NULL;
	(void) argc;
	while (true)
	{
		cmd_line = get_line();
		if (cmd_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = _tokenize(cmd_line);
		if (!command)
			continue;
		status = execute(command, argv);
	}
	return (0);
}
