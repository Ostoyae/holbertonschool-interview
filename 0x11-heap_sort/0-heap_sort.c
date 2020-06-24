#include "sort.h"

/**
 * heap_sort - sorts an array for least significant to most
 * @array: pointer to array to sort
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (int) size / 2 - 1; i >= 0; i--)
		heapify(array, size, (int) size, i);

	for (i = size - 1; i > 0; i--)
	{
		_swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}

}

/**
 * heapify - heaping
 * @arr: array
 * @arr_size: size of array;
 * @h_size: heap size
 * @idx: starting node index in array
 */
void heapify(int *arr, size_t arr_size, int h_size, int idx)
{

	int p, l, r;

	p = idx;
	l = 2 * idx + 1;
	r = 2 * idx + 2;
	if (l < h_size && arr[l] > arr[p])
		p = l;

	if (r < h_size && arr[r] > arr[p])
		p = r;

	if (p != idx)
	{
		_swap(&arr[idx], &arr[p]);
		print_array(arr, arr_size);
		heapify(arr, arr_size, h_size, p);
	}
}

/**
 * _swap - swap values of 2 pointers
 * @a: pointer
 * @b: pointer
 */
void _swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
