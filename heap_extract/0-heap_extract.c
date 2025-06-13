#include "binary_trees.h"

/**
 * get_heap_size - calculates the size of a heap
 * @root: pointer to the root node of the heap
 *
 * Return: size of the heap
 */
size_t get_heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * get_last_node - finds the last node in level order traversal
 * @root: pointer to the root node of the heap
 * @index: current index in level order
 * @size: total size of the heap
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);

	if (index == size)
		return (root);

	left = get_last_node(root->left, 2 * index + 1, size);
	if (left)
		return (left);

	right = get_last_node(root->right, 2 * index + 2, size);
	return (right);
}

/**
 * heapify_down - restores the max heap property by moving a node down
 * @root: pointer to the root node to heapify
 */
void heapify_down(heap_t *root)
{
	heap_t *largest, *left, *right;
	int temp;

	if (!root)
		return;

	largest = root;
	left = root->left;
	right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 if function fails
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int extracted_value;
	size_t size;

	if (!root || !*root)
		return (0);

	extracted_value = (*root)->n;

	/* If only one node in the heap */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	/* Find the last node in level order */
	size = get_heap_size(*root);
	last_node = get_last_node(*root, 0, size - 1);

	/* Replace root value with last node value */
	(*root)->n = last_node->n;

	/* Remove the last node */
	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	free(last_node);

	/* Restore heap property */
	heapify_down(*root);

	return (extracted_value);
}
