#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - function that implements the bubble sort algorithim
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: returns the sorted list in ascendind order
 */
void bubble_sort(int *array, size_t size)
{
	int j, temp;
	size_t i;
	bool swapped;


	if (array == NULL)
	return;

	j = 0;
	do {
		swapped = false;
		for (i = 0; i < (size - 1 - j); i++)
		{
			if (array[i] > array[i + 1])
			{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
			swapped = true;
			}
		}
		j++;
	} while (swapped);
}
