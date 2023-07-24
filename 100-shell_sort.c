#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t gap = 1;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
	for (i = gap; i < size; i++)
	{
	temp = array[i];
	j = i;
	while (j > gap - 1 && array[j - gap] >= temp)
	{
		array[j] = array[j - gap];
		j = j - gap;
	}
	array[j] = temp;
	}
	print_array(array, size);
	gap = (gap - 1) / 3;
	}
}
