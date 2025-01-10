#include "main.h"

/**
 * print_env - prints the current enviroment variables
 */

void print_env(void)
{
	int n = 0;

	while (environ[n])
	{
		printf("%s\n", environ[n]);
		n++;
	}
}

/**
 * handle_builtins - handles built-in commands like "exit" and "env"
 *
 * @line: input command line
 * @argv: parsed arguments
 *
 * Return: 1 if a built-in command is handled, 0 otherwise
 */

int handle_builtins(char *line, char **argv)
{
	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(0);
	}

	if (argv[0] && strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0)
}
