#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t size;

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	if (tree == NULL)
		return (0);

	if ((size_t)((1 << height) - 1) == size)
		return (1);

	return (0);
}
