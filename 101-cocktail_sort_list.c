#include "sort.h"
#include <stdbool.h>

/**
 * cocktail_sort_list - sorts a double linked list using the coctail_sor
 * algorithim
 * @list: the list to be sorted
 *
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	listint_t *left = *list;
	listint_t *right = NULL;

	if (*list == NULL || (*list)->next == NULL)
	return;

	do
	{
	swapped = false;
	while (left != right)
	{
	if (left->n > left->next->n)
	{
	swapnodes(list, left, left->next);
	swapped = true;
	print_list(*list);
	}
	else
	{
	left = left->next;
	}
	}
	if (!swapped)
	break;
	right = left;
	while (right != *list)
	{
	if (right->n < right->prev->n)
	{
	swapnodes(list, right->prev, right);
	swapped = true;
	print_list(*list);
	left = right;
	}
	else
	{
	right = right->prev;
	}
	}
	} while (swapped);
}
     
/**
 * swapnodes swaps the nodes in the list
 * @list: the list whose nodes is being swapped
 * @node1: the node to be swapped
 * @nodes2:the ndes to be swapped
 *
 */
void swapnodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	node1->prev->next = node2;
	if (node2->prev)
	node2->prev->next = node1;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->prev = node2;

	if (!node2->prev)
	*list = node2;
}
