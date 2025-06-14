#!/usr/bin/python3
"""Island Perimeter"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
    grid (list[list[int]]): Island grid where 0 is water and 1 is land

    Returns:
    int: The perimeter of the island
    """
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])
    land_count = 0
    adjacent_count = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                land_count += 1
                if j + 1 < cols and grid[i][j + 1] == 1:
                    adjacent_count += 1
                if i + 1 < rows and grid[i + 1][j] == 1:
                    adjacent_count += 1

    return land_count * 4 - adjacent_count * 2
