#include "binary_trees.h"


/**
 * Insert a node into a max binary heap.
 * @root
 * @value
 * @return
 */
heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t *node, *cur_node;
    if (!root || !(*root))
	return (*root = binary_tree_node(NULL, value));

    cur_node = *root;

    /* handle changes at root level*/
    if (value > cur_node->n)
    {
	node = binary_tree_node(cur_node->parent, value);
	/* check if node is complete NULL - NULL*/
	if (!(!cur_node->left && !cur_node->right))
	{
	    node->right = cur_node;
	    node->left = cur_node->left;
	    cur_node->left = NULL;
	} else
	    node->left = cur_node;

	node->left->parent = node;
	cur_node->parent = node;
	if (node->right)
	    node->right->parent = node;

	*root = node;
	return (node);
    }

    if ((cur_node->left && cur_node->right) &&
	value > cur_node->left->n &&
	value < cur_node->right->n)
    {
	node = heap_insert(&cur_node->left, value);
	node->parent = cur_node;
	return node;
    }

    /*check if node left or right are unassigned*/
    if (!(cur_node->left && cur_node->right))
    {
	node = binary_tree_node(cur_node, value);
	if (!cur_node->left)
	    cur_node->left = node;
	else
	    cur_node->right = node;

    } else if (value < cur_node->left->n)
	node = heap_insert(&cur_node->left, value);
    else if (value > cur_node->left->n && !branch_complete(cur_node->left))
    {
	node = heap_insert(&cur_node->left, value);
	node->parent = cur_node;
    } else if (value > cur_node->left->n && value > cur_node->right->n && branch_complete(cur_node->left))
    {
	node = heap_insert(&cur_node->right, value);
	node->parent = cur_node;
    } else
	node = NULL;


    return (node);
}

bool branch_complete(const binary_tree_t *root)
{
    bool left, right;
    if (!root->left && !root->right)
	return true;

    if (root->left)
	left = branch_complete(root->left);
    if (root->right)
	right = branch_complete(root->right);

    return (left && right);
}

bool is_complete(const binary_tree_t *root)
{
    return (!root->left && !root->right);
}

bool has_leaves(const binary_tree_t *root)
{
    return (root->left && root->right);
}



