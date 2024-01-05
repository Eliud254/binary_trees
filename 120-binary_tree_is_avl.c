#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (tree == NULL)
        return (0);
    else
    {
        if (tree)
        {
            left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
            right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
        }
        return ((left_height > right_height) ? left_height : right_height);
    }
}

/**
 * bal_avl - Auxiliar function to compare each subtree if it's AVL.
 * @tree: Node pointing to the tree to check.
 * @lower: Node pointing to the lower limit.
 * @high: Node pointing to the higher limit.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
    size_t height_l, height_r, balancer;

    if (tree != NULL)
    {
        if (tree->n > high || tree->n < lower)
        {
            return (0);
        }
        height_l = binary_tree_height(tree->left);
        height_r = binary_tree_height(tree->right);
        balancer = height_l > height_r ? height_l - height_r : height_r - height_l;
        if (balancer > 1)
        {
            return (0);
        }
        return (bal_avl(tree->left, lower, tree->n - 1) &&
                bal_avl(tree->right, tree->n + 1, high));
    }
    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Node pointing to the tree to check.
 * Return: 1 if the tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }
    return (bal_avl(tree, INT_MIN, INT_MAX));
}

