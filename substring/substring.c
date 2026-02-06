/*
 * File: substring.c
 * Auth: Your Name
 */

#include <stdlib.h>
#include "substring.h"

/**
 * _strlen - Computes the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
static int _strlen(char const *s)
{
	int len = 0;

	while (s && s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strncmp - Compares two strings up to n characters.
 * @s1: First string.
 * @s2: Second string.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if equal, a positive or negative value otherwise.
 */
static int _strncmp(char const *s1, char const *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/**
 * is_valid - Checks if a valid concatenation starts at a position.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: Number of words in the array.
 * @word_len: Length of each word.
 * @pos: Starting index in @s.
 * @used: Auxiliary array to mark used words.
 *
 * Return: 1 if valid, 0 otherwise.
 */
static int is_valid(char const *s, char const **words, int nb_words,
	int word_len, int pos, int *used)
{
	int i, j, k;
	char const *segment;

	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	for (j = 0; j < nb_words; j++)
	{
		segment = s + pos + j * word_len;
		for (k = 0; k < nb_words; k++)
		{
			if (!used[k] && _strncmp(segment, words[k], word_len) == 0)
			{
				used[k] = 1;
				break;
			}
		}
		if (k == nb_words)
			return (0);
	}
	return (1);
}

/**
 * scan_substrings - Scans string for valid concatenations.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: Number of words in the array.
 * @word_len: Length of each word.
 * @len_s: Length of @s.
 * @used: Auxiliary array to mark used words.
 * @indices: Output array for indices, or NULL to only count.
 *
 * Return: Number of valid substrings found.
 */
static int scan_substrings(char const *s, char const **words, int nb_words,
	int word_len, int len_s, int *used, int *indices)
{
	int i, count = 0, total_len = word_len * nb_words;

	for (i = 0; i <= len_s - total_len; i++)
	{
		if (is_valid(s, words, nb_words, word_len, i, used))
		{
			if (indices)
				indices[count] = i;
			count++;
		}
	}
	return (count);
}

/**
 * find_substring - Finds all starting indices of substrings containing all
 * words exactly once.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: Number of elements in @words.
 * @n: Address at which to store the number of indices found.
 *
 * Return: Pointer to an array of indices, or NULL if none found or on error.
 */
int *find_substring(char const *s, char const **words,
	int nb_words, int *n)
{
	int *indices = NULL;
	int *used;
	int len_s, word_len, total_len;
	int count;

	if (!s || !words || !n || nb_words <= 0)
		return (NULL);
	*n = 0;
	len_s = _strlen(s);
	word_len = _strlen(words[0]);
	if (word_len == 0)
		return (NULL);
	total_len = word_len * nb_words;
	if (total_len > len_s)
		return (NULL);
	used = malloc(sizeof(int) * nb_words);
	if (!used)
		return (NULL);
	count = scan_substrings(s, words, nb_words, word_len, len_s, used, NULL);
	if (count == 0)
	{
		free(used);
		return (NULL);
	}
	indices = malloc(sizeof(int) * count);
	if (!indices)
	{
		free(used);
		return (NULL);
	}
	count = scan_substrings(s, words, nb_words, word_len, len_s, used, indices);
	free(used);
	*n = count;
	return (indices);
}
