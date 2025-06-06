# Slide Line - 2048 Game Mechanics

This project implements the core mechanics of the 2048 game for a single horizontal line. The goal is to slide and merge an array of integers either to the left or right, following the same rules as the popular 2048 puzzle game.

## Description

The `slide_line` function reproduces the 2048 game mechanics on a single horizontal line. Given an array of integers, it can slide and merge the elements in a specified direction. Identical numbers that are contiguous or separated by zeros will be merged according to 2048 rules.

## Files

- `slide_line.h` - Header file containing function prototypes and macro definitions
- `0-slide_line.c` - Implementation of the slide_line function and helper functions

## Function Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

### Parameters

- `line`: Pointer to an array of integers containing `size` elements
- `size`: Number of elements in the array
- `direction`: Direction to slide and merge (`SLIDE_LEFT` or `SLIDE_RIGHT`)

### Return Value

- `1` upon success
- `0` upon failure (invalid direction or NULL pointer)

## Macros

- `SLIDE_LEFT` (0) - Slide and merge elements to the left
- `SLIDE_RIGHT` (1) - Slide and merge elements to the right

## Rules

1. **Sliding**: Non-zero elements move toward the specified direction
2. **Merging**: Identical adjacent numbers (or separated by zeros) combine into their sum
3. **2048 Logic**: Each number can only participate in one merge per operation
4. **Zero Handling**: Zeros are treated as empty spaces and are filled appropriately

## Examples

### Slide Left Examples

```bash
Input:  [2, 2, 0, 0]
Output: [4, 0, 0, 0]

Input:  [2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4]
Output: [4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

### Slide Right Examples

```bash
Input:  [2, 2, 2, 2]
Output: [0, 0, 4, 4]

Input:  [2, 2, 2, 2, 2]
Output: [0, 0, 2, 4, 4]

Input:  [4, 4, 8, 16]
Output: [0, 8, 8, 16]
```

### No Change Examples

```bash
Input:  [2, 4, 8, 16] (left or right)
Output: [2, 4, 8, 16]
```

## Compilation

The code is designed to compile on Ubuntu 14.04 LTS with gcc 4.8.4 using strict compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -o slide_line main.c 0-slide_line.c
```

## Usage

```c
#include "slide_line.h"

int main(void)
{
    int line[] = {2, 2, 0, 0};
    size_t size = 4;

    if (slide_line(line, size, SLIDE_LEFT))
    {
        /* line now contains [4, 0, 0, 0] */
        printf("Success!\n");
    }

    return (0);
}
```

## Implementation Details

- **No Dynamic Memory**: Uses only stack-allocated arrays
- **Betty Style**: Follows Betty coding style guidelines
- **Error Handling**: Validates input parameters
- **Helper Functions**: Separate functions for left and right sliding logic
- **Efficient**: Processes arrays in a single pass with temporary storage

## Algorithm

1. **Extract Non-Zero Elements**: Copy non-zero values to temporary array
2. **Merge Pass**: Combine adjacent identical elements from the movement direction
3. **Place Results**: Position merged elements in the target direction
4. **Fill Zeros**: Fill remaining positions with zeros

## Testing

The implementation has been tested with various scenarios including:
- Basic merging cases
- Multiple consecutive identical numbers
- Arrays with mixed zeros and numbers
- Edge cases with no possible merges
- Large arrays with complex merge patterns