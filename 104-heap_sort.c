#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Array to be sorted
 * @start: Index of the root element of the heap
 * @end: Index of the last element in the array
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child;
    int temp;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        if (child + 1 <= end && array[child] < array[child + 1])
            child++;
        if (array[root] < array[child])
        {
            temp = array[root];
            array[root] = array[child];
            array[child] = temp;
            print_array(array, size);
            root = child;
        }
        else
            return;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t end = size - 1;
    size_t start = (size - 2) / 2;
    size_t i;

    for (i = start; i < size; i--)
        sift_down(array, i, end, size);
    for (i = end; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        sift_down(array, 0, i - 1, size);
    }
}

