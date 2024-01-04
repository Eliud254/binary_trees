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
* binary_tree_is_bst - Checks if a binary tree is a valid BST
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is a valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left && tree->left->n >= tree->n) ||
		(tree->right && tree->right->n <= tree->n))
		return (0);

	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is a valid AVL Tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height, right_height;

	if (!binary_tree_is_bst(tree))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height - right_height > 1 || right_height - left_height > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
