#include "binary_trees.h"

/**
* check_bst - Helper function to check if a binary tree is a valid BST
* @tree: Pointer to the root node of the tree to check
* @min: Pointer to the minimum value to be compared with the tree nodes
* @max: Pointer to the maximum value to be compared with the tree nodes
*
* Return: 1 if the tree is a valid BST, 0 otherwise
*/
int check_bst(const binary_tree_t *tree, const int *min, const int *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= *min) || (max != NULL && tree->n >= *max))
		return (0);

	return (check_bst(tree->left, min, &(tree->n)) &&
			check_bst(tree->right, &(tree->n), max));
}

/**
* binary_tree_is_bst - Checks if a binary tree is a valid BST
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is a valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, NULL, NULL));
}
