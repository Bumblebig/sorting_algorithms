#include "sort.h"

/**
 * item_swap - Swaps items in array.
 * @arr: array to modify
 * @l: index of the left item.
 * @r: index of the right item.
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
 * quick_sort_range_lomuto - Sorts a sub array using Lomuto's partition scheme.
 * @arr: array containing sub-array.
 * @l: starting position of sub-array.
 * @h: ending position of sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_lomuto(int *arr, size_t l, size_t h, size_t size)
{
	size_t j, i;
	int pivot;

	if ((l >= h) || (arr == NULL))
		return;
	pivot = arr[h];
	j = l;
	for (i = l; i < h; i++)
	{
		if (arr[i] <= pivot)
		{
			if (j != i)
			{
				item_swap(arr, j, i);
				print_array(arr, size);
			}
			k++;
		}
	}
	if (j != h)
	{
		item_swap(arr, j, h);
		print_array(arr, size);
	}
	if (j - l > 1)
		quick_sort_range_lomuto(arr, l, j - 1, size);
	if (h - j > 1)
		quick_sort_range_lomuto(arr, j + 1, h, size);
}

/**
 * quick_sort - Sorts array using quick sort algorithm
 * and Lomuto's partition scheme.
 * @arr: array to sort.
 * @size: length of the array.
 */
void quick_sort(int *arr, size_t size)
{
	if (arr != NULL)
	{
		quick_sort_range_lomuto(arr, 0, size - 1, size);
	}
}
