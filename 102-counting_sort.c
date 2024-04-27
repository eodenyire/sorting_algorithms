#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    size_t i, max = 0;

    if (size < 2 || !array)
        return;

    /* Find the maximum element in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > (int)max)
            max = array[i];
    }

    /* Create a counting array of size max + 1 and initialize to 0 */
    count_array = malloc(sizeof(int) * (max + 1));
    if (!count_array)
        return;
    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Count occurrences of each element */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Modify count_array to hold actual positions */
    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    /* Allocate memory for the sorted array */
    sorted_array = malloc(sizeof(int) * size);
    if (!sorted_array)
    {
        free(count_array);
        return;
    }

    /* Build the sorted array */
    for (i = 0; i < size; i++)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    /* Print the counting array */
    printf("%d", count_array[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Free memory */
    free(count_array);
    free(sorted_array);
}

