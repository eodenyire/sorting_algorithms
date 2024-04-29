#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merge subarrays in bitonic sequence
 * @array: Array to be sorted
 * @start: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = start; i < start + k; ++i)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Merging [%lu/%lu] (%s):\n", k, count, dir ? "UP" : "DOWN");
                print_array(array + start, count);
            }
        }

        bitonic_merge(array, start, k, dir);
        bitonic_merge(array, start + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: Array to be sorted
 * @start: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, start, k, 1);
        bitonic_sort_recursive(array, start + k, k, 0);
        bitonic_merge(array, start, count, dir);
    }
}

/**
 * bitonic_sort - Sort an array in bitonic order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}


