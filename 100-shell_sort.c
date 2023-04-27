#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @arr: array to sort.
 * @size: length of the array.
 */
void shell_sort(int *arr, size_t size)
{
	int i, j, tmp, gaps= 0;

	if ((arr == NULL) || (size < 2))
		return;
	while (gaps <= ((int)size / 3))
		gaps = (gaps * 3) + 1;
	for (; gaps > 0; )
	{
		for (i = gaps; i < (int)size; i++)
		{
			tmp = arr[i];
			for (j = i; (j >= gaps) && (arr[j - gaps] > tmp); j -= gaps)
			{
				arr[j] = arr[j - gaps];
			}
			arr[j] = tmp;
		}
		gaps = (gaps - 1) / 3;
		print_array(arr, size);
	}
}
