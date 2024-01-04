#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserts a node as the right child of another node
* @parent: Pointer to the node to insert the right-child in
* @value: Value to store in the new node
*
* Return: Pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		temp = parent->right;
		new_node->right = temp;
		temp->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
