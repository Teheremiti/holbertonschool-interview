#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	/* If pattern is empty, string must also be empty */
	if (!*pattern)
		return (!*str);

	/* Check if next character in pattern is '*' */
	if (*(pattern + 1) == '*')
	{
		/* Try matching zero occurrences of the preceding character */
		if (regex_match(str, pattern + 2))
			return (1);

		/* If current characters match, try matching one or more */
		if (*str && (*str == *pattern || *pattern == '.'))
			return (regex_match(str + 1, pattern));

		return (0);
	}

	/* If no '*' follows, current characters must match */
	if (*str && (*str == *pattern || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
