#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <sys/types.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size (max + 1) */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    /* Initialize all elements of the counting array to 0 */
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    /* Count occurrences of each element in the original array */
    for (size_t i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    /* Print the counting array */
    printf("\n");
    for (int i = 0; i <= max; i++)
    {
        printf("%d%s", count[i], (i == max) ? "\n" : ", ");
    }
    printf("\n");

    /* Modify the counting array to hold the cumulative counts */
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    /* Create a temporary array to hold the sorted result */
    int *temp = malloc(size * sizeof(int));
    if (temp == NULL)
    {
        free(count);
        return;
    }

    /* Place elements in their correct sorted position */
    for (ssize_t i = size - 1; i >= 0; i--)
    {
        temp[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (size_t i = 0; i < size; i++)
    {
        array[i] = temp[i];
    }

    /* Free allocated memory */
    free(temp);
    free(count);
}

