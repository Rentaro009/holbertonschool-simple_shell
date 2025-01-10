#include "main.h"

/**
 * _isspace - checks if a character is a whitespace character
 *
 * @c: character to check
 *
 * Return: 1 if the character is a whitespace, 0 otherwise
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r');
}

/**
 * trim_spaces - trims leading and trailing spaces from a string
 *
 * @line: sting to trim
 *
 * Return: pointer to the trimmed string
 */

char *trim_spaces(char *line)
{
	char *start = line, *end;

	while (*start && _isspace(*start))
		start++;

	if (*start == '\0')
		return (start);

	end = start + strlen(start) - 1;
	while (end > start && _isspace(*end))
		end--;

	*(end + 1) = '\0';

	return (start);
}
