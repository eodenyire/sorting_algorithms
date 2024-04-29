#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Get the maximum element from an array
 * @array: The array
 * @size: Size of the array
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
 * countingSort - Sort an array using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent value
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

    for (i = size - 1; i > 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (size < 2)
        return;

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

