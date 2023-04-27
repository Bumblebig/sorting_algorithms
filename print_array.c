#include <stdio.h>

/**
 * print_array - Prints array of integers.
 * @array: array to be printed.
 * @size: Number of elements in @array.
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	while ((array != NULL) && (i < size))
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}