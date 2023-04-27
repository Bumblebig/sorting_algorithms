#include "sort.h"

/**
 * item_swap - Swaps two items in an array.
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
 * s_down - Moves largest element in an array
 * @arr: array to sort.
 * @arr_size: length of the array.
 * @size: length of the max heap sub-array.
 * @pos: position of largest element
 */
void s_down(int *arr, int arr_size, int size, int pos)
{
	int j, c;

	j = pos;
	while (j < (size / 2))
	{
		c = (2 * j) + 1;
		if ((c < (size - 1)) && (arr[c] < arr[c + 1]))
			c++;
		if (arr[j] >= arr[c])
			return;
		item_swap(arr, j, c);
		print_array(arr, arr_size);
		j = c;
	}
}

/**
 * max_heap - Builds a max heap binary tree
 * @arr: array to convert to a max heap binary tree.
 * @size: The length of the array.
 */
void max_heap(int *arr, int size)
{
	int a;

	for (a = (size / 2) - 1; a >= 0; a--)
	{
		s_down(arr, size, size, a);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @arr:y array to sort.
 * @size: length of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, j;

	max_heap(array, size);
	j = size;
	for (i = 0; i < (int)size; i++)
	{
		item_swap(array, --n, 0);
		if (j != 0)
		{
			print_array(array, size);
			sift_down(array, size, j, 0);
		}
	}
}
