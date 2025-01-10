#include "main.h"

/**
 * execute_command - Executes a command in a child process
 *
 * @cmd: full path ot the command
 * @argv: arguments for the command
 *
 * Return: exit status of the executed command
 */

int execute_command(char *cmd, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else
	{
		perror("fork");
		free(cmd);
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 * _fork - handles the execution of a command, including built-ins
 *
 * @line: input string containing the command to execute
 *
 * Return: exit status of the executed command, or 127 if it is not found
 */

int _fork(char *line)
{
	char *argv[100], *cmd;

	tokenize_input(line, argv);

	if (handle_builtins(line, argv))
		return (0);

	cmd = find_command_in_path(argv[0]);
	if (!cmd)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}

	return (execute_command(cmd, argv));
}
