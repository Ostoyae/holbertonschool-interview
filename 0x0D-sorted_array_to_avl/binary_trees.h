#ifndef INTERVIEW_BINARY_TREES_H
#define INTERVIEW_BINARY_TREES_H

#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;

void print_array(const int *array, size_t size);
void binary_tree_print(const binary_tree_t *);
char **binary_tree_string(const binary_tree_t *tree);

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl_rec(int *array, avl_t *parent, size_t size, size_t start, size_t end);

#endif