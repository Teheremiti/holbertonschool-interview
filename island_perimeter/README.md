# Island Perimeter

This project contains a function to calculate the perimeter of an island in a 2D grid.

## Description

The `island_perimeter` function calculates the perimeter of an island described in a grid where:
- `0` represents water
- `1` represents land
- Each cell is a square with side length 1
- Cells are connected horizontally/vertically (not diagonally)
- The grid is rectangular with width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or nothing)
- The island doesn't have "lakes" (water inside that isn't connected to surrounding water)

## Function Signature

```python
def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid (list[list[int]]): Island grid where 0 is water and 1 is land

    Returns:
        int: the perimeter of the island
    """
```

## Algorithm

For each land cell (1) in the grid:
1. Check all 4 neighbors (up, down, left, right)
2. If a neighbor is water (0) or out of bounds, add 1 to the perimeter
3. Return the total perimeter count

## Usage

```python
#!/usr/bin/python3
island_perimeter = __import__('0-island_perimeter').island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]

print(island_perimeter(grid))  # Output: 12
```

## Files

- `0-island_perimeter.py`: Contains the main function implementation
- `README.md`: This documentation file
