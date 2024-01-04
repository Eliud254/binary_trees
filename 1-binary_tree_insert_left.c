#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the left child of another node
* @parent: Pointer to the node to insert the left-child in
* @value: Value to store in the new node
*
* Return: Pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		temp = parent->left;
		new_node->left = temp;
		temp->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
