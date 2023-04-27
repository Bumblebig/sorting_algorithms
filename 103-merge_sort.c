#include "sort.h"

/**
 * td_merge - Merges array
 * @arr: array to merge.
 * @arr_c: temporary array.
 * @l: left index of the split-array.
 * @m: mid-point of the split-array.
 * @r: right index of the split-array.
 */
void td_merge(int *arr, int *arr_c, size_t l, size_t m, size_t r)
{
	size_t a = l, b = m, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + l, m - l);
	printf("[right]: ");
	print_array(arr + (m), r - m);
	for (c = l; c < r; c++)
	{
		if ((a < m) && ((b >= r) || (arr_c[a] <= arr_c[b])))
		{
			arr[c] = arr_c[a++];
		}
		else
		{
			arr[c] = arr_c[b++];
		}
	}
	printf("[Done]: ");
	print_array(arr + l, r - l);
}

/**
 * sp_merge - Sorts array splited using the
 * merge sort algorithm.
 * @arr: array that has been split.
 * @arr_c: temporary array.
 * @size: length of the original array.
 * @l: left index of the split-array.
 * @r: right index of the split-array.
 */
void s_merge(int *arr, int *arr_c, size_t size, size_t l, size_t r)
{
	size_t i, mid;

	if ((r - l) <= 1)
		return;
	mid = (l + r) / 2;
	s_merge(arr, arr_c, size, l, mid);
	s_merge(arr, arr_c, size, mid, r);
	for (i = l; i <= r + (r == size ? -1 : 0); i++)
		arr_c[i] = arr[i];
	td_merge(arr, arr_c, l, mid, r);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @arr: array to sort.
 * @size: length of the array.
 */
void merge_sort(int *arr, size_t size)
{
	size_t i;
	int *arr_c = NULL;

	if (arr != NULL)
	{
		arr_c = malloc(sizeof(int) * size);
		if (arr_c != NULL)
		{
			for (i = 0; i < size; i++)
				arr_c[i] = arr[i];
			s_merge(arr, arr_c, size, 0, size);
			free(arr_c);
		}
	}
}
