#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: unsorted array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;

	if (!array || size <= 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* insures not to sort an already sorted array */
		swapped = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
}
