`heap_insert` project
=====================

This project implements basic operations for a Max Binary Heap using the
`binary_tree_t` structure.

**Task 0: New node**

Write a function `binary_tree_node` that creates a new binary tree node:
- **Prototype**: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- The new node stores `value` in `n`.
- The `parent` pointer is set to the node passed as argument.
- The `left` and `right` children are initialized to `NULL`.
- The function returns a pointer to the new node, or `NULL` on failure.
