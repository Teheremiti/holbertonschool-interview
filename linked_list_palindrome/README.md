# Palindrome Linked List Checker

This project implements a function to check if a singly linked list is a palindrome. A palindrome reads the same forwards and backwards, and this implementation efficiently determines whether the values in a linked list form a palindrome sequence.

## Description

The `is_palindrome` function checks if a singly linked list contains values that form a palindrome. The function handles edge cases such as empty lists (considered palindromes) and single-node lists, while efficiently processing lists of any size.

## Files

- `lists.h` - Header file containing structure definitions and function prototypes
- `0-is_palindrome.c` - Main implementation of the palindrome checking function
- `linked_lists.c` - Helper functions for linked list operations (for testing purposes)

## Function Prototype

```c
int is_palindrome(listint_t **head);
```

### Parameters

- `head`: Double pointer to the first node of the linked list

### Return Value

- `1` if the linked list is a palindrome
- `0` if the linked list is not a palindrome or on failure
- `1` for empty lists (considered palindromes by definition)

## Data Structure

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

- `n`: Integer value stored in the node
- `next`: Pointer to the next node in the list

## Algorithm

The implementation uses a two-pass approach:

1. **Count Phase**: Traverse the list once to count the total number of nodes
2. **Store Phase**: Allocate an array and store all node values sequentially
3. **Check Phase**: Compare values from both ends of the array moving toward the center
4. **Cleanup**: Free allocated memory and return the result

### Time Complexity: O(n)
### Space Complexity: O(n)

Where n is the number of nodes in the linked list.

## Examples

### Palindrome Cases

```c
// List: 1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1
// Result: 1 (is palindrome)

// List: 1 -> 2 -> 1
// Result: 1 (is palindrome)

// List: 5
// Result: 1 (single node is palindrome)

// List: NULL (empty)
// Result: 1 (empty list is palindrome)
```

### Non-Palindrome Cases

```c
// List: 1 -> 2 -> 3 -> 4 -> 5
// Result: 0 (not palindrome)

// List: 1 -> 2 -> 3 -> 2 -> 2
// Result: 0 (not palindrome)
```

## Compilation

The code is designed to compile on Ubuntu 14.04 LTS with gcc 4.8.4 using strict compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Usage Example

```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;

    // Build a palindrome: 1 -> 2 -> 1
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);

    if (is_palindrome(&head) == 1)
        printf("List is a palindrome\n");
    else
        printf("List is not a palindrome\n");

    free_listint(head);
    return (0);
}
```

## Helper Functions (for testing)

### `print_listint`
```c
size_t print_listint(const listint_t *h);
```
Prints all elements of the list and returns the number of nodes.

### `add_nodeint_end`
```c
listint_t *add_nodeint_end(listint_t **head, const int n);
```
Adds a new node with value `n` at the end of the list.

### `free_listint`
```c
void free_listint(listint_t *head);
```
Frees all nodes in the linked list.

## Implementation Details

- **Memory Management**: Uses `malloc` to allocate temporary storage and properly frees it
- **Error Handling**: Returns 0 if memory allocation fails or invalid parameters are provided
- **Edge Cases**: Handles empty lists, single nodes, and NULL pointers correctly
- **Betty Style**: Follows Betty coding style guidelines with proper documentation
- **No Global Variables**: All variables are local to maintain clean code structure

## Algorithm Walkthrough

1. **Input Validation**: Check if head is NULL or points to NULL (empty list)
2. **Count Nodes**: Traverse the list once to determine the size
3. **Allocate Memory**: Create an integer array to store node values
4. **Copy Values**: Store all node values in the array sequentially
5. **Palindrome Check**: Compare array[i] with array[size-1-i] for i from 0 to size/2
6. **Return Result**: Free memory and return 1 for palindrome, 0 otherwise

## Testing

The function has been tested with:
- Various palindrome sequences of different lengths
- Non-palindrome sequences
- Empty lists
- Single-node lists
- Lists with duplicate values
- Large lists to verify memory management