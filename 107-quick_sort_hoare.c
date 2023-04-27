#include "sort.h"

/**
 * item_swap - Swaps items in array.
 * @array: array to modify.
 * @l: index of the left item.
 * @r: index of the right item.
 */
void item_swap(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_hoare - Sorts a sub array using the
 * quick sort algorithm and Hoare's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_hoare(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (TRUE)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			item_swap(array, i, j);
			print_array(array, size);
		}
		else
		{
			break;
		}
	}
	quick_sort_range_hoare(array, low, j - (j == high), size);
	quick_sort_range_hoare(array, j - (j == high) + 1, high, size);
}

/**
 * quick_sort_hoare - Sorts an array using the quick sort algorithm
 * and Hoare's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if ((array != NULL) && (size > 1))
	{
		quick_sort_range_hoare(array, 0, size - 1, size);
	}
}
