#include "sort.h"

/**
 * counting_sort - sorts array using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, *count_arr, j;
	size_t i, index;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
		max = array[i];
		}
	}

	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr == NULL)
	return;
	for (j = 0; j <= max; j++)
	count_arr[j] = 0;

	for (i = 0; i < size; i++)
	count_arr[array[i]]++;
	print(count_arr, max + 1);

	index = 0;
	for (j = 0; j <= max; j++)
	{
	while (count_arr[j] > 0)
	{
	array[index] = j;
	index++;
	count_arr[j]--;
	}
	}
	free(count_arr);
}
/**
 * print - prints the counting array
 * @array: the counting array
 * @size: size of the array
 */
void print(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
	printf("%d", array[i]);
	if (i < size - 1)
	{
	printf(", ");
	}
	}
	printf("\n");
}
