#include "main.h"

/**
 * tokenize_input - tokenizes the input string into arguments
 *
 * @line: input string containing the command
 * @argv: array to store the arguments
 *
 * Return: number of tokens parsed
 */

int tokenize_input(char *line, char **argv)
{
	int n = 0;

	argv[n] = strtok(line, " ");
	while (argv[n] != NULL && n < 99)
	{
		n++;
		argv[n] = strtok(NULL, " ");
	}
	return (n);
}
