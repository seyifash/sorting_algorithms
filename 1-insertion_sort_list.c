#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: the list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *curr_prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = tmp)
	{
		tmp = curr->next;
		curr_prev = curr->prev;
		while (curr_prev != NULL && curr->n < curr_prev->n)
		{
			swap_nodes(list, &curr_prev, curr);
			print_list((const listint_t *)*list);
		}

	}


}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
