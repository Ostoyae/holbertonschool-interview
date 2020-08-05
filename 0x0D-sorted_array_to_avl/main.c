#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	int array[] = {
		1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98
	};

	size_t n = sizeof(array) / sizeof(array[0]);

	tree = sorted_array_to_avl(array, n);
	if (!tree)
		return (1);
	_print_array(array, n);
	binary_tree_print(tree);
	return (0);
}