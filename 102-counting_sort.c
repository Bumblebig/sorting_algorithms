#include "sort.h"

/**
 * counting_sort - Sorts array using counting sort algorithm.
 * @arr: array to sort.
 * @size: length of the array.
 */
void counting_sort(int *arr, size_t size)
{
	int *count_arr = NULL, *arr_sorted = NULL, max_value = 0;
	size_t i;

	if ((arr == NULL) || (size < 2))
		return;
	for (i = 0; i < size; i++)
	{
		max_value = (arr[i] > max_value ? arr[i] : max_value);
		if (arr[i] < 0)
			return;
	}
	count_arr = malloc(sizeof(int) * (max_val + 1));
	if (count_arr == NULL)
		return;
	arr_sorted = malloc(sizeof(int) * size);
	if (arr_sorted == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < (size_t)(max_value + 1); i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[arr[i]]++;
	for (i = 1; i < (size_t)(max_value + 1); i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max_value + 1);
	for (i = size - 1; ; i--)
	{
		count_arr[arr[i]]--;
		arr_sorted[count_arr[arr[i]]] = arr[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		arr[i] = arr_sorted[i];
	free(arr_sorted), free(count_arr);
}
