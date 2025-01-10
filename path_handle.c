#include "main.h"
/**
 * get_path_env - Gets the value of the PATH or PATH1 environment var
 *
 * Return: Ptr to value of PATH or PATH1
 */
char *get_path_env(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}

	i = 0;
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH1=", 6) == 0)
			return (environ[i] + 6);
		i++;
	}

	return (NULL);
}


/**
 * find_command_in_path - Finds the path of the command
 * @command: The command to searched for
 *
 * Return: Ptr to str containing the entire path
 */
char *find_command_in_path(char *command)
{
	struct stat st;
	char *path, *path_copy, *token, *full_path;

	if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(command));


	path = get_path_env();
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
