#include "binary_trees.h"

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	binary_tree_t *current;
	int front = 0, rear = 0, flag = 0;

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];

		if (current == NULL)
		{
			flag = 1;
		}
		else
		{
			if (flag)
			{
				free(queue);
				return (0);
			}

			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);
	return (1);
}
