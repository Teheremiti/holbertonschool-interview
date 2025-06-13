#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the maximum value in an array
 * @array: The array to find maximum in
 * @size: Number of elements in the array
 *
 * Return: The maximum value in the array
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array || size == 0)
		return (0);

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Performs counting sort for a specific digit
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current digit position (1, 10, 100, etc.)
 */
static void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i;
	int j;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	if (!output || !count)
	{
		free(output);
		free(count);
		return;
	}
	/* Initialize count array */
	for (j = 0; j < 10; j++)
		count[j] = 0;
	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	/*
	 * Change count[i] so that count[i] now contains actual
	 * position of this digit in output[]
	 */
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];
	/* Build the output array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	/*
	 * Copy the output array to array[], so that array[] now
	 * contains sorted numbers according to current digit
	 */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the LSD Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/*
	 * Do counting sort for every digit. Note that instead
	 * of passing digit number, exp is passed. exp is 10^i
	 * where i is current digit number
	 */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
