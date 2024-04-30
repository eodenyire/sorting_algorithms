#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *               Bubble Sort algorithm
 *
 * @array: pointer to the array of integers to be sorted
 * @size: number of elements in the array
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Bubble Sort algorithm. It repeatedly steps through
 *              the list, compares adjacent elements, and swaps them if they
 *              are in the wrong order. This process is repeated until the
 *              array is sorted.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, if_sorted;
	/* Check if array is NULL or empty */
	if (!array || size == 0)
		return;

	do {
		if_sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				if_sorted = 0;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}

	} while (if_sorted == 0);
}
