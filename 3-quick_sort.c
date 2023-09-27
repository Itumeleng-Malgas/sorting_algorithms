#include "sort.h"

/**
 * swap_int_q - function to swap two integers
 *
 * @x: first integer
 * @y: second integer
 */
void swap_int_q(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: pointer to the array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: Pivot index
 */
size_t lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_int_q(&array[i], &array[j]);
		}
	}

	swap_int_q(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 *
 * @array: pointer to the array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = lomuto_partition(array, low, high);

		print_array(array, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers using Quick Sort
 *
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return; /* Nothing to sort */

	quick_sort_recursive(array, 0, size - 1, size);
}
