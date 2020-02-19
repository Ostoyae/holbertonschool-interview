//
// Created by msmit on 2/17/2020.
//

#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    binary_tree_print(root);
    root->left->left = binary_tree_node(root->left, 6);
    binary_tree_print(root);
    root->left->right = binary_tree_node(root->left, 16);
    binary_tree_print(root);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    root->right->left = binary_tree_node(root->right, 256);
    binary_tree_print(root);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}