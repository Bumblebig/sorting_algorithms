#include "sort.h"

/**
 * bubble_sort - Sorts array using bubble sort algorithm.
 * @array: array to sort
 * @size: length of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, b;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b + 1] < array[b])
			{
				SWAP(array, b, b + 1);
				print_array(array, size);
			}
		}
	}
}
