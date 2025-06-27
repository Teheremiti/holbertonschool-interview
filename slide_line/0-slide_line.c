#include "slide_line.h"

/**
 * slide_left - Slides and merges line to the left
 * @line: Pointer to array of integers
 * @size: Size of the array
 *
 * Return: void
 */
static void slide_left(int *line, size_t size)
{
	size_t i, j = 0;
	int temp[1024]; /* Temporary array to store non-zero elements */
	size_t temp_size = 0;

	/* Copy non-zero elements to temp array */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			temp[temp_size] = line[i];
			temp_size++;
		}
	}

	/* Merge adjacent identical elements */
	if (temp_size > 1)
	{
		for (i = 0; i < temp_size - 1; i++)
		{
			if (temp[i] == temp[i + 1])
			{
				temp[i] *= 2;
				temp[i + 1] = 0;
				i++; /* Skip next element as it's been merged */
			}
		}
	}

	/* Copy merged elements back, skipping zeros */
	for (i = 0; i < temp_size; i++)
	{
		if (temp[i] != 0)
		{
			line[j] = temp[i];
			j++;
		}
	}

	/* Fill remaining positions with zeros */
	while (j < size)
	{
		line[j] = 0;
		j++;
	}
}

/**
 * slide_right - Slides and merges line to the right
 * @line: Pointer to array of integers
 * @size: Size of the array
 *
 * Return: void
 */
static void slide_right(int *line, size_t size)
{
	int temp[1024]; /* Temporary array to store result */
	size_t i, j;
	int write_idx;

	/* Initialize temp array */
	for (i = 0; i < size; i++)
		temp[i] = 0;

	/* Process from right to left */
	write_idx = size - 1;
	i = size;
	while (i > 0)
	{
		i--;
		if (line[i] != 0)
		{
			/* Check if we can merge with the next element */
			j = i;
			while (j > 0 && line[j - 1] == 0)
				j--;

			if (j > 0 && line[j - 1] == line[i])
			{
				/* Merge */
				temp[write_idx] = line[i] * 2;
				line[j - 1] = 0; /* Mark as used */
				i = j - 1; /* Skip the merged element */
			}
			else
			{
				/* No merge, just copy */
				temp[write_idx] = line[i];
			}
			write_idx--;
		}
	}

	/* Copy result back */
	for (i = 0; i < size; i++)
		line[i] = temp[i];
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers containing size elements
 * @size: Size of the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}

