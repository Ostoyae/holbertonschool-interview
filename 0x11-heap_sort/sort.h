#ifndef INTERVIEW_SORT_H
#define INTERVIEW_SORT_H

#include <stdlib.h>

void heap_sort(int *array, size_t size);

void print_array(const int *array, size_t size);

void heapify(int *arr, size_t arr_size, int h_size, int idx);
void _swap(int *a, int *b);

#endif
