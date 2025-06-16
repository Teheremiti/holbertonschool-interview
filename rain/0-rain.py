#!/usr/bin/python3
"""Rain Water Trapping"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
    walls (list): List of non-negative integers representing wall heights

    Returns:
    int: Total amount of rainwater retained

    The algorithm works by finding the water level at each position, which is
    determined by the minimum of the maximum heights to the left and right.
    Water trapped at each position = min(left_max, right_max) - wall_height
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array - maximum height to the left (including current)
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array - maximum height to the right (including current)
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water trapped at each position
    water = 0
    for i in range(n):
        # Water level is limited by the lower of left_max and right_max
        water_level = min(left_max[i], right_max[i])
        # Only add water if the level is above the current wall
        if water_level > walls[i]:
            water += water_level - walls[i]

    return water
