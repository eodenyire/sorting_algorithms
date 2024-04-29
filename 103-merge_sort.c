#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: Pointer to the original array
 * @left: Index of the left subarray
 * @middle: Index marking the end of the left subarray and the start of the right subarray
 * @right: Index of the right subarray
 */
void merge(int *array, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    /* Create temporary arrays */
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    /* Merge the temporary arrays back into array[left..right] */
    i = 0; /* Initial index of first subarray*/
    j = 0; /*Initial index of second subarray*/
    k = left; /* Initial index of merged subarray*/
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if any */
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if any */
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    /* Free temporary arrays */
    free(L);
    free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t middle;

    if (size < 2)
        return;

    /* Calculate middle index */
    middle = size / 2;

    /* Recursive calls to merge_sort */
    merge_sort(array, middle); /* Sort left subarray*/
    merge_sort(array + middle, size - middle); /* Sort right subarray*/

    /* Merge the sorted subarrays */
    merge(array, 0, middle - 1, size - 1);
    printf("\nMerging...\n");
    printf("[left]: ");
    print_array(array, middle);
    printf("[right]: ");
    print_array(array + middle, size - middle);
    printf("[Done]: ");
    print_array(array, size);
}
