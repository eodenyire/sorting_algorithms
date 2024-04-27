#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *ptr, *tmp;

    if (!list || !(*list) || !((*list)->next))
        return;

    ptr = (*list)->next;

    while (ptr)
    {
        tmp = ptr;
        ptr = ptr->next;

        while (tmp->prev && (tmp->n < tmp->prev->n))
        {
            if (tmp->next)
                tmp->next->prev = tmp->prev;

            tmp->prev->next = tmp->next;
            tmp->next = tmp->prev;
            tmp->prev = tmp->prev->prev;

            if (tmp->prev)
                tmp->prev->next = tmp;
            else
                *list = tmp;

            if (tmp->next)
                tmp->next->prev = tmp;

            print_list(*list);
        }
    }
}
