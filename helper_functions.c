#include "sort.h"

/**
 * swap - function to swap two integers
 *
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
