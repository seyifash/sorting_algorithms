#include "sort.h"
/**
 * swaps - swap the array
 * @a: value to swap
 * @b: value to swap
 *
 */
void swaps(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * sift_down - sift the array
 * @array: the array
 * @root: tye root
 * @size; size of the array
 */
void sift_down(int *array, size_t root, size_t size)
{
	size_t max_child;

	while (2 * root + 1 < size)
	{
	max_child = 2 * root + 1;

        if (max_child + 1 < size && array[max_child] < array[max_child + 1])
	{
	max_child++;
	}

        if (array[root] >= array[max_child])
	{
	break;
	}

	swaps(&array[root], &array[max_child]);
	print_array(array, size);
	root = max_child;
	}
}
/**
 * heapify - helper function
 * @array: the array
 * @size:  the size
 *
 */
void heapify(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i > 0; i--) 
	{
	sift_down(array, i - 1, size);
	}
}
/**
 * heap_sort - help function
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	heapify(array, size);

	for (i = size - 1; i > 0; i--) {
        swaps(&array[0], &array[i]);
        print_array(array, size);

        sift_down(array, 0, i);
	}
}
