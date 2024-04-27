#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
    listint_t *temp_prev = (*a)->prev;
    listint_t *temp_next = (*b)->next;

    if (temp_prev)
        temp_prev->next = *b;
    if (temp_next)
        temp_next->prev = *a;
    (*a)->prev = *b;
    (*a)->next = temp_next;
    (*b)->next = *a;
    (*b)->prev = temp_prev;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *curr;
    int swapped = 1;

    if (!list || !(*list) || !((*list)->next))
        return;

    while (swapped)
    {
        swapped = 0;
        for (curr = *list; curr->next != NULL; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(&curr, &(curr->next));
                if (!curr->prev)
                    *list = curr;
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        curr = curr->prev; 
        for (; curr != NULL && curr->prev != NULL; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(&(curr->prev), &curr);
                if (!curr->prev)
                    *list = curr;
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

