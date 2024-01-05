#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *temp;
    size_t height, i;
    int mask;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);
    mask = 1 << (height - 1);
    temp = *root;

    for (i = 0; i < height - 1; i++)
    {
        if (!(mask & i))
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!temp->parent)
        *root = NULL;
    else if (temp->parent->right)
        temp->parent->right = NULL;
    else
        temp->parent->left = NULL;

    if (temp != *root)
    {
        temp->left = (*root)->left;
        temp->right = (*root)->right;

        if (temp->left)
            temp->left->parent = temp;

        if (temp->right)
            temp->right->parent = temp;

        temp->parent = (*root)->parent;

        if ((*root)->parent->left == *root)
            (*root)->parent->left = temp;
        else
            (*root)->parent->right = temp;
    }

    free(*root);
    *root = last_node;
    heapify_down(*root);

    return (value);
}
