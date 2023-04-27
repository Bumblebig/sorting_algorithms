#include "sort.h"

/**
 * counting_sort - Sorts array using counting sort algorithm.
 * @array: array to sort.
 * @size: length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr = NULL, *arr_sorted = NULL, max_value = 0;
	size_t i;

	if ((array == NULL) || (size < 2))
		return;
	for (i = 0; i < size; i++)
	{
		max_value = (array[i] > max_value ? array[i] : max_value);
		if (array[i] < 0)
			return;
	}
	count_arr = malloc(sizeof(int) * (max_value + 1));
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
		count_arr[array[i]]++;
	for (i = 1; i < (size_t)(max_value + 1); i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max_value + 1);
	for (i = size - 1; ; i--)
	{
		count_arr[array[i]]--;
		arr_sorted[count_arr[array[i]]] = array[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = arr_sorted[i];
	free(arr_sorted), free(count_arr);
}
