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
	listint_t *left, *right;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

		while (swapped
		{
		swapped = 0;
		for (left = *list; left->next != NULL; left = left->next
		{
		right = left->next;
		if (left->n > right->n)
		{
		swap_nodes(&left, &right);
		if (!left->prev)
			*list = left;
			swapped = 1;
			print_list(*list);
		}
		}	
	if (!swapped
		break;
	swapped = 0;
	for (right = left; right->prev != NULL; right = right->prev
	{
	left = right->prev;
		if (left->n > right->n)
		{
		swap_nodes(&left, &right);
		if (!left->prev)
			*list = left;
		swapped = 1;
		print_list(*list);
		}
	}
	}
}
