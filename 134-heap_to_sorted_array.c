#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary
 *            Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Sorted array of integers (in descending order)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i;

    if (!heap || !size)
        return (NULL);

    *size = binary_tree_size(heap);
    sorted_array = malloc(*size * sizeof(int));

    if (!sorted_array)
        return (NULL);

    for (i = 0; i < *size; i++)
        sorted_array[i] = heap_extract(&heap);

    return (sorted_array);
}
