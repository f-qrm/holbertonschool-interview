#include <stdlib.h>
#include "binary_trees.h"

/**
 * bubble_up - Bubbles up a node in a Max Binary Heap
 * @node: Pointer to the node to bubble up
 *
 * Return: Pointer to the node after bubbling up
 */
static heap_t *bubble_up(heap_t *node)
{
int tmp;
while (node->parent && node->n > node->parent->n)
{
tmp = node->n;
node->n = node->parent->n;
node->parent->n = tmp;
node = node->parent;
}
return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *file[1024];
heap_t *current, *node;
int front, back;
if (*root == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}
front = 0;
back = 0;
file[back++] = *root;
while (front < back)
{
current = file[front++];
if (current->left == NULL)
{
current->left = binary_tree_node(current, value);
node = current->left;
return (bubble_up(node));
}
else if (current->right == NULL)
{
current->right = binary_tree_node(current, value);
node = current->right;
return (bubble_up(node));
}
else
{
file[back++] = current->left;
file[back++] = current->right;
}
}
return (NULL);
}
