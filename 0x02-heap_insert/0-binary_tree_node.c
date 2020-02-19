#include "binary_trees.h"

/**
 * binary_tree_node - Constructs a new node
 * with a defined Parent node and value,
 * @parent : pointer to a node to assign as Parent
 * @value : value to assign the node to
 * Return: pointer to the newly constructed node or else NULL if error.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = malloc(sizeof(binary_tree_t));
if (!node)
{
return (NULL);
}
node->parent = parent;
node->left = node->right = NULL;
node->n = value;
return (node);
}
