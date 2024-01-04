#include "binary_trees.h"

/**
* binary_tree_height - Measures the height
*                      of a binary tree
* @tree: Pointer to the root node of the
*                  tree to measure the height
*
* Return: Height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}

/**
* binary_tree_is_perfect - function that checks if a binary tree is perfect.
* @tree: is a pointer to the root node of the tree to check.
* Return: If tree is NULL, your function must return 0.
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		else if (tree->left != NULL && tree->right != NULL)
			return (binary_tree_is_perfect(tree->left) &&
							binary_tree_is_perfect(tree->right));
	}

	return (0);
}
