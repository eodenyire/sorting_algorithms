#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Gets the maximum element from an array
 * @array: The array
 * @size: Number of elements in the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * countingSort - Sorts an array of integers based on significant digits
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The significant digit to sort by
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output = NULL;
    int count[10] = {0};
    size_t i;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers using Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = getMax(array, size);
    size_t i;
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

