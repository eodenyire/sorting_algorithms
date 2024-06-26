#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting Sort algorithm.
 *
 * This algorithm sorts an array by counting the number of occurrences
 * of each distinct element and using arithmetic to determine the
 * positions of each element in the sorted output array.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int n, j, *count_array, *aux;
	size_t i;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	}
	count_array = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, n + 1);
	aux = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		aux[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = aux[i];
	}
	free(aux);
	free(count_array);
}
