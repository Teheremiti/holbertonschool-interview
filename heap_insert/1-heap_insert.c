#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * heapify_up - Restores Max Heap property by bubbling a node up
 * @node: Pointer to the node to heapify from
 *
 * Return: Pointer to the node in its final position
 */
static heap_t *heapify_up(heap_t *node)
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
 * get_node_by_index - Retrieves a node by its index (1-based) in a tree
 *                     interpreted as an array representation
 * @root: Pointer to the root node of the tree
 * @index: Index of the node to retrieve (1-based)
 * @current: Current node index (start with 1 for root)
 *
 * Return: Pointer to the node at the given index, or NULL if not found
 */
static heap_t *get_node_by_index(heap_t *root, size_t index, size_t current)
{
	heap_t *node;

	if (root == NULL)
		return (NULL);

	if (current == index)
		return (root);

	node = get_node_by_index(root->left, index, current * 2);
	if (node != NULL)
		return (node);

	return (get_node_by_index(root->right, index, current * 2 + 1));
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size, parent_index, new_index;
	heap_t *parent, *node;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	new_index = size + 1;
	parent_index = new_index / 2;
	parent = get_node_by_index(*root, parent_index, 1);
	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (new_index == parent_index * 2)
		parent->left = node;
	else
		parent->right = node;

	return (heapify_up(node));
}
