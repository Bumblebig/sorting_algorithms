#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: array to sort.
 * @size: length of the array.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, tmp, gaps= 0;

	if ((array == NULL) || (size < 2))
		return;
	while (gaps <= ((int)size / 3))
		gaps = (gaps * 3) + 1;
	for (; gaps > 0; )
	{
		for (i = gaps; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; (j >= gaps) && (array[j - gaps] > tmp); j -= gaps)
			{
				array[j] = array[j - gaps];
			}
			array[j] = tmp;
		}
		gaps = (gaps - 1) / 3;
		print_array(array, size);
	}
}
