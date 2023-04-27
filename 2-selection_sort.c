#include "sort.h"

/**
 * item_swap - Swaps two items
 * @arr: array to modify
 * @l: index of the left item.
 * @r:  index of the right item.
 */
void item_swap(int *arr, size_t l, size_t r)
{
	int tmp;

	if (arr != NULL)
	{
		tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
	}
}

/**
 * selection_sort - Sorts array using selection sort algorithm.
 * @arr: array to sort
 * @size: length of the array.
 */
void selection_sort(int *arr, size_t size)
{
	size_t i, j, l_index;

	if (arr != NULL)
	{
		for (i = 0; i < size - 1; i++)
		{
			l_index = i;
			for (j = size - 1; j > i; j--)
			{
				if (arr[j] < arr[l_index])
				{
					l_index = j;
				}
			}
			if (i != l_index)
			{
				item_swap(arr, i, l_index);
				print_array(arr, size);
			}
		}
	}
}
