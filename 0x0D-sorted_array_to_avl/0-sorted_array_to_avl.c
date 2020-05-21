#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>


static avl_t *new_node(int n, avl_t *parent);

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;
	size_t h_idx;

	if (!array || size == 0)
		return (NULL);
	h_idx = size / 2;
	if (h_idx % 2 == 0)
		h_idx--;
	head = new_node(array[h_idx], NULL);
	head->left = sorted_array_to_avl_rec(
		array, head, size, 0, h_idx - 1);
	head->right = sorted_array_to_avl_rec(
		array, head, size, h_idx + 1, size - 1);

	return (head);
}

avl_t *sorted_array_to_avl_rec(int *array, avl_t *parent,
                               size_t size, size_t start,
                               size_t end)
{
	avl_t *head;
	size_t h_idx;

	if (start >= size / 2)
	{
		/** right **/
		if (end == start)
		{
			head = new_node(array[end], parent);
			if (end + 1 == size )
			{
				parent->right = parent->left;
				parent->left = NULL;
			}
			return head;
		} else if (end == size / 2)
		{
			return (NULL);
		}
	}

	if (end <= size / 2)
	{
		/** left **/
		if (start == end)
			return new_node(array[start], parent);
		else if (end < start)
			return (NULL);
	}

	h_idx = (end - start) / 2;

	if (start > size / 2)
		h_idx += start;

	head = new_node(array[h_idx], parent);

	head->left = sorted_array_to_avl_rec(array, head, size, start, h_idx - 1);
	head->right = sorted_array_to_avl_rec(array, head, size, h_idx + 1, end);
	return (head);
}

static avl_t *new_node(int n, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parent;
	node->left = node->right = NULL;
	if (parent)
	{
		if (!parent->left)
			parent->left = node;
		else if (!parent->right)
			parent->right = node;
	}
	return (node);
}