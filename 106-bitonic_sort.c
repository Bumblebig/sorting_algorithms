#include "sort.h"

/**
 * item_swap - Swaps two items in array.
 * @arr: array to modify.
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
 * bitonic_merge - Merges items in a sub-array based on a given order.
 * @array: array to sort.
 * @size: length of the array (should be a power of 2).
 * @low: starting position of the sub-array.
 * @n: length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t n, char ascending)
{
	size_t i, m;

	if ((array != NULL) && (n > 1))
	{
		m = n / 2;
		for (i = low; i < (low + m); i++)
		{
			if ((array[i] > array[i + m]) == ascending)
			{
				item_swap(array, i, i + m);
			}
		}
		bitonic_merge(array, size, low, m, ascending);
		bitonic_merge(array, size, low + m, m, ascending);
	}
}

/**
 * bitonic_sort_split - Sorts a sub-array using the bitonic algorithm.
 * @arr: array to sort.
 * @size: length of the array (should be a power of 2).
 * @low: starting position of the sub-array.
 * @n: length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_sort_split(int *arr, size_t size, size_t low, size_t n, char ascending)
{
	size_t m;

	if ((arr != NULL) && (n > 1))
	{
		m = n / 2;
		printf("Merging [%d/%d] (%s):\n", (int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(arr + low, n);
		bitonic_sort_split(arr, size, low, m, TRUE);
		bitonic_sort_split(arr, size, low + m, m, FALSE);
		bitonic_merge(arr, size, low, n, ascending);
		printf("Result [%d/%d] (%s):\n"), ((int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(arr + low, n);
	}
}

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm.
 * @array: array to sort.
 * @size: length of the array (should be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		bitonic_sort_split(array, size, 0, size, TRUE);
	}
}
