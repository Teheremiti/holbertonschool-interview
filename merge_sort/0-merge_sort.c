#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * PrintArray - prints array of integers for range of indices
 * @array: array of values to be printed
 * @iBeg: starting index value
 * @iEnd: ending index value
 */
static void PrintArray(int *array, int iBeg, int iEnd)
{
	int i;

	if (!array)
		return;

	for (i = iBeg; i < iEnd; i++)
	{
		if (i < iEnd - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

/**
 * CopyArray - simple 1 for 1 copy of source[] to dest[]
 * @source: array of values to be sorted
 * @iBeg: starting index value
 * @iEnd: ending index value
 * @dest: array to store sorted integers
 */
static void CopyArray(int *source, int iBeg, int iEnd, int *dest)
{
	int i;

	if (!source || !dest)
		return;

	for (i = iBeg; i < iEnd; i++)
		dest[i] = source[i];
}

/**
 * TopDownMerge - sorts subsections ("runs") of source[] by ascending value
 * @source: array of values to be sorted
 * @iBeg: left run starting index value
 * @iMid: right run starting index value
 * @iEnd: right run ending index value
 * @dest: array to store sorted integers
 */
static void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int i, j, k;

	if (!source || !dest)
		return;

	i = iBeg;
	j = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, iBeg, iMid);
	printf("[right]: ");
	PrintArray(source, iMid, iEnd);

	for (k = iBeg; k < iEnd; k++)
	{
		if (i < iMid && (j >= iEnd || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}

	printf("[Done]: ");
	PrintArray(dest, iBeg, iEnd);
}

/**
 * TopDownSplitMerge - recursive engine of merge_sort
 * @source: array of integers to be sorted
 * @iBeg: starting index value
 * @iEnd: ending index value
 * @dest: array to store sorted integers
 */
static void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (!source || !dest)
		return;

	if (iEnd - iBeg < 2)
		return;

	iMid = (iEnd + iBeg) / 2;

	TopDownSplitMerge(dest, iBeg, iMid, source);
	TopDownSplitMerge(dest, iMid, iEnd, source);
	TopDownMerge(source, iBeg, iMid, iEnd, dest);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *              using the top-down Merge Sort algorithm
 * @array: array of integers to be sorted
 * @size: number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);
	if (!work_copy)
		return;

	CopyArray(array, 0, (int)size, work_copy);
	TopDownSplitMerge(work_copy, 0, (int)size, array);

	free(work_copy);
}