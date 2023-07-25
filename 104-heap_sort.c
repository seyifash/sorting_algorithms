#include "sort.h"

/**
 * siftDown - implements the siftdown method
 * @array: the array to be sorted
 * @root: the root of the array
 * @last: the last
 *
 */
void siftDown(int *array, size_t root, size_t last)
{
	size_t bigger = 2 * root + 1;
	int temp;
	size_t i;

	while (bigger <= last)
	{
	if (bigger < last && array[bigger + 1] > array[bigger])
	{
	bigger++;
	}
	if (array[root] >= array[bigger])
	{
	break;
	}
	temp = array[root];
	array[root] = array[bigger];
	array[bigger] = temp;
	root = bigger;
	bigger = 2 * root + 1;
	for (i = 0; i <= last; i++)
	{
	printf("%d ", array[i]);
	}
	printf("\n");
	}
}

/**
 * heap_sort - implements the heap sort algorithms
 * @array: the array
 * @size: the size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t h, k, i;
	int temp;

	for (h = size / 2; h > 0; h--)
	{
	siftDown(array, h - 1, size - 1);
	}
	for (k = size; k > 1; k--)
	{
	temp = array[k - 1];
	array[k - 1] = array[0];
	array[0] = temp;
	siftDown(array, 0, k - 2);
	for (i = 0; i < k - 1; i++)
	{
	printf("%d ", array[i]);
	}
	printf("\n");
	}
}
