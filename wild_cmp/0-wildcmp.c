#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: first string
 * @s2: second string (can contain '*' wildcards)
 *
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If we've reached the end of the pattern */
	if (*s2 == '\0')
		return (*s1 == '\0');

	/* If current character in pattern is '*' */
	if (*s2 == '*')
	{
		/* Try matching '*' with empty string */
		if (wildcmp(s1, s2 + 1))
			return (1);

		/* Try matching '*' with one or more characters */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		return (0);
	}

	/* If current character is not '*' */
	/* Check if we've reached end of s1 or characters don't match */
	if (*s1 == '\0' || *s1 != *s2)
		return (0);

	/* Characters match, continue with next characters */
	return (wildcmp(s1 + 1, s2 + 1));
}
