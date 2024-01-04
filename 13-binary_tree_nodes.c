#include "binary_trees.h"

/**
* binary_tree_nodes - Counts the number of nodes with at least 1 child
* @tree: Pointer to the root node of the tree to count nodes
*
* Return: Number of nodes in the tree (excluding leaves), 0 if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes;
	size_t right_nodes;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (1 + left_nodes + right_nodes);
}
