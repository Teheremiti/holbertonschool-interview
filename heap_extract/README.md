# Heap Extract - Max Binary Heap Root Extraction

This project implements a function to extract the root node from a Max Binary Heap while maintaining the heap property. The function removes the maximum element (root) and reorganizes the remaining elements to preserve the max heap structure.

## Description

The `heap_extract` function extracts the root node of a Max Binary Heap, which contains the maximum value. After extraction, the heap is restructured by replacing the root with the last level-order node and then restoring the max heap property through a heapify-down operation.

## Files

- `binary_trees.h` - Header file containing structure definitions and function prototypes
- `0-heap_extract.c` - Main implementation of the heap extraction function
- `binary_tree_print.c` - Visualization function for binary trees (for testing purposes)
- `libheap.a` - Static library containing helper functions (provided for testing)

## Data Structures

### Binary Tree Node
```c
typedef struct binary_tree_s
{
    int n;                          /* Integer stored in the node */
    struct binary_tree_s *parent;   /* Pointer to the parent node */
    struct binary_tree_s *left;     /* Pointer to the left child node */
    struct binary_tree_s *right;    /* Pointer to the right child node */
} binary_tree_t;
```

### Max Binary Heap
```c
typedef struct binary_tree_s heap_t;
```

## Function Prototype

```c
int heap_extract(heap_t **root);
```

### Parameters

- `root`: Double pointer to the root node of the heap

### Return Value

- The value stored in the root node (maximum value)
- `0` if the function fails or the heap is empty

## Algorithm

The heap extraction follows these steps:

1. **Validation**: Check if the heap exists and is not empty
2. **Store Root Value**: Save the root's value to return later
3. **Handle Single Node**: If only one node exists, free it and set root to NULL
4. **Find Last Node**: Locate the last node in level-order traversal
5. **Replace Root**: Move the last node's value to the root position
6. **Remove Last Node**: Delete the last node and update parent pointers
7. **Heapify Down**: Restore the max heap property by moving the new root value down

### Time Complexity: O(log n)
### Space Complexity: O(log n) due to recursion

Where n is the number of nodes in the heap.

## Max Heap Property

A Max Binary Heap maintains the following properties:
- **Complete Binary Tree**: All levels are filled except possibly the last level, which is filled from left to right
- **Max Heap Property**: Every parent node has a value greater than or equal to its children

## Example Usage

```c
#include "binary_trees.h"

int main(void)
{
    heap_t *root;
    int extracted_value;

    /* Assume root points to a valid max heap */

    extracted_value = heap_extract(&root);
    printf("Extracted maximum value: %d\n", extracted_value);

    /* The heap is now reorganized with a new maximum at the root */

    return (0);
}
```

## Example Execution

```
Initial heap:
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)

Extracted: 98

After extraction:
                 .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
```

## Implementation Details

### Helper Functions

#### `get_heap_size`
```c
size_t get_heap_size(heap_t *root);
```
Calculates the total number of nodes in the heap using recursive traversal.

#### `get_last_node`
```c
heap_t *get_last_node(heap_t *root, size_t index, size_t size);
```
Finds the last node in level-order traversal using the complete binary tree property.

#### `heapify_down`
```c
void heapify_down(heap_t *root);
```
Restores the max heap property by comparing a node with its children and swapping if necessary, then recursively applying the process.

### Edge Cases Handled

- **Empty heap**: Returns 0 without crashing
- **Single node heap**: Properly frees the node and sets root to NULL
- **Two node heap**: Correctly handles parent-child relationships
- **Memory management**: No memory leaks in all scenarios

## Compilation

The code is designed to compile on Ubuntu 14.04 LTS with gcc 4.8.4 using strict compilation flags:

```bash
gcc -Wall -Wextra -Werror -pedantic -o heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
```

## Testing

The implementation has been tested with:
- Various heap sizes (from single node to large heaps)
- Complete extraction scenarios (extracting all nodes)
- Memory leak detection using valgrind
- Edge cases (empty heaps, single nodes)

## Algorithm Walkthrough

1. **Input Validation**: Verify root pointer is valid and heap exists
2. **Value Storage**: Store the root's value for return
3. **Size Calculation**: Count total nodes to find the last node
4. **Last Node Location**: Use level-order indexing to find the rightmost node at the bottom level
5. **Value Replacement**: Copy the last node's value to the root
6. **Node Removal**: Delete the last node and update its parent's pointer
7. **Heap Restoration**: Apply heapify-down starting from the root
8. **Return**: Provide the extracted maximum value

## Performance Characteristics

- **Extraction**: O(log n) - heapify operation
- **Space**: O(log n) - recursion depth for heapify
- **Memory**: No additional heap allocation during extraction