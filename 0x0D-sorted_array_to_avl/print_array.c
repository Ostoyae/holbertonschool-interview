#include "binary_trees.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void _print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}