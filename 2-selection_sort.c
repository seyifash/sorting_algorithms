#include "sort.h"
/**
* selection_sort - sorts array in ascending using the selection sort algorithm
* @array: the array to be sorted
* @size: size of the array
* Return: returns a sorted array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, min, j, temp;

	if (!array || size < 2)
	return;
	for (i = 0; i < size - 1; i++)
	{
	min = i;
	for (j = i + 1; j < size; j++)
	{
	if (array[j] < array[min])
	{
	min = j;
	}
	}
	if (min != i)
	{
	temp = array[i];
	array[i] = array[min];
	array[min] = temp;
	print_array(array, size);
	}
	}
}
