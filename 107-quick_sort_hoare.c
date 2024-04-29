#include <stdio.h>
#include "sort.h"

/**
 * hoare_partition - Implements the Hoare partition scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        if (i != j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
}

/**
 * quick_sort_hoare_recursive - Recursively sorts the array using Quick Sort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = hoare_partition(array, low, high, size);
        quick_sort_hoare_recursive(array, low, pi, size);
        quick_sort_hoare_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, 0, size - 1, size);
}

