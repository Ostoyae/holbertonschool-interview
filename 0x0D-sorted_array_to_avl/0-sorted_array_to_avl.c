#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>


/**
 * sorted_array_to_avl - entry to sorting array to nodes
 * @array: array to sort
 * @size: size of array
 * Return: pointer to sorted
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (!array || size == 0)
		return (NULL);

	head = sorted_array_to_avl_rec(
		array, NULL, 0, size - 1);

	return (head);
}

/**
 * sorted_array_to_avl_rec - receive solve
 * @array: array to sort
 * @parent : parent to use
 * @start : start of slice
 * @end:  of slice
 * Return: pointer to sorted
 */
avl_t *sorted_array_to_avl_rec(int *array,
	avl_t *parent,
	int start,
	int end)
{
	avl_t *head;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (size_t)(start + end) / 2;

	head = new_node(array[mid], parent);
	head->left = sorted_array_to_avl_rec(array, head, start, mid - 1);
	head->right = sorted_array_to_avl_rec(array, head, mid + 1, end);

	return (head);
}

/**
 * new_node - stuff
 * @n: number to set new node
 * @parent: parent to give node
 * Return: pointer to new node
 */
static avl_t *new_node(int n, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
