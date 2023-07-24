#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition_func(int *array, int low, int high, size_t size);
void quicksort_recurssion(int *array, int low, int high, size_t size);
void swap(int *array, int *i, int *j, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void swapnodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int left_size, int *right, int right_size);
void print_merge_step(int *left, size_t leftsize, size_t rightsize, int *righ);

#endif
