#include "sort.h"
#include <stdio.h>
/**
 * _swap - Swaps two elements in an array.
 *
 * @array: The array to modify.
 * @i: The index of the first element.
 * @j: The index of the second element.
 *
 * Description: This function swaps two elements in the array.
 */
void _swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * shell_sort - Sorts an array using the Shell Sort algorithm.
 *
 * @array: The array to sort.
 * @size: Size of the array.
 *
 * Description: This function sorts an array using the Shell Sort algorithm
 * which is an extension of insertion sort. It divides the initial unsorted
 * list into smaller sublists using a gap value, and then sorts these sublists
 * using insertion sort. The gap value decreases in each iteration until it
 * becomes 1, where the last iteration performs a standard insertion sort.
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				_swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
