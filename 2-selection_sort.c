#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function implements the selection sort algorithm,
 *              which repeatedly selects the smallest element from the
 *              unsorted portion of the array and swaps it with the
 *              first unsorted element. This process continues until
 *              the entire array is sorted.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, step, min_idx;
	int temp;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
		}

		if (min_idx != step)
		{
			temp = array[step];
			array[step] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
