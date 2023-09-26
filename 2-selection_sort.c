#include "sort.h"

/**
 * swap_int - function to swap two integers
 *
 * @x: first integer
 * @y: second integer
 */
void swap_int(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order.
 *
 * @array: An array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
		return; /* Nothing to sort */

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			swap_int(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
