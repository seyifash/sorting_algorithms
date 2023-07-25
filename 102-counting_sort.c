#include "sort.h"

/**
 * counting_sort - sorts array using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, *count_arr, j, *temp;
	size_t i;

	if (size <= 1)
	return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr == NULL)
	return;
	for (j = 0; j <= max; ++j)
	count_arr[j] = 0;
	for (i = 0; i < size; i++)
	{
	count_arr[array[i]]++;
	}

	for (j = 1; j <= max; j++)
	{
	count_arr[j] += count_arr[j - 1];
	}
	print(count_arr, max + 1);
	temp = malloc(sizeof(int) * (size + 1));

	for (j = size - 1; j >= 0; j--)
	{
	temp[count_arr[array[j]] - 1] = array[j];
	count_arr[array[j]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(count_arr);
	free(temp);
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
