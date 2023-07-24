#include "sort.h"
/**
 * merge_sort - uses the merge sort algorithm to sort an array
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t left_size, right_size;
	int *left, *right;
	size_t i;

	if (size <= 1)
	return;

	left_size = size / 2;
	right_size = size - left_size;
	left = (int *)malloc(left_size * sizeof(int));
	right = (int *)malloc(right_size * sizeof(int));
	for (i = 0; i < left_size; i++)
	left[i] = array[i];
	for (i = 0; i < right_size; i++)
	right[i] = array[left_size + i];
	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, left_size, right, right_size);
	free(left);
	free(right);
}
/**
 * merge - merges the sorted portion of the right and left sie
 * @array: the array
 * @left: left side of the array
 * @right: right side of the array
 * @left_size: size for the left side
 * @right_size: size for the right sze
 */
void merge(int *array, int *left, int left_size, int *right, int right_size)
{
	int i = 0, j = 0, k = 0;
	int merged_size = left_size + right_size;

	print_merge_step(left, left_size, right_size, right);
	while (i < left_size && j < right_size)
	{
	if (left[i] <= right[j])
	array[k++] = left[i++];
	else
	array[k++] = right[j++];
	}

	while (i < left_size)
	array[k++] = left[i++];

	while (j < right_size)
	array[k++] = right[j++];
	printf("[Done]: ");
	for (k = 0; k < merged_size; k++)
	{
	printf("%d", array[k]);
	if (k < merged_size - 1)
	printf(", ");
	else
	printf("\n");
	}
}

/**
 * print_merge_step - prints the value of left and right before merge
 * @left: left side of the array
 * @leftsize: size f the left prtion of the array
 * @rightsize: right side of the array
 * @right: the right portio of the array
 *
 */
void print_merge_step(int *left, size_t leftsize, size_t rightsize, int *righ)
{
	size_t i, j;

	printf("Merging...\n");

	printf("[left]: ");
	for (i = 0; i < leftsize; i++)
	{
	printf("%d", left[i]);
	if (i < leftsize - 1)
	printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (j = 0; j < rightsize; j++)
	{
	printf("%d", right[j]);
	if (j < rightsize - 1)
	printf(", ");
	}
	printf("\n");
}
