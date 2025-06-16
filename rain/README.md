# Rain Water Trapping

## Description

This project contains a solution to the classic "Rain Water Trapping" problem. Given a list of non-negative integers representing the heights of walls, the function calculates how many square units of water will be retained after it rains.

## Problem Statement

Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

## Requirements

- Prototype: `def rain(walls)`
- `walls` is a list of non-negative integers
- Return: Integer indicating total amount of rainwater retained
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water
- If the list is empty return 0

## Files

- `0-rain.py`: Contains the `rain` function implementation

## Algorithm

The solution uses a **two-pass approach**:

### Step 1: Calculate Maximum Heights
1. **Left pass**: For each position, find the maximum wall height to the left (including current position)
2. **Right pass**: For each position, find the maximum wall height to the right (including current position)

### Step 2: Calculate Water Level
For each position, the water level is determined by:
```
water_level = min(left_max, right_max)
```

### Step 3: Calculate Trapped Water
Water trapped at each position:
```
water_trapped = max(0, water_level - wall_height)
```

The total is the sum of water trapped at all positions.

## Visual Example

For walls `[0, 1, 0, 2, 0, 3, 0, 4]`:

```
    |
    |   |
    | | |
  | | | |
0 1 0 2 0 3 0 4

After rain:
    |
    |~~~|
    |~|~|
  |~|~|~|
0 1 0 2 0 3 0 4
```

Water trapped: 1 + 2 + 3 = 6 units

## Time Complexity

- **Time**: O(n) - Three passes through the array
- **Space**: O(n) - Two additional arrays for left_max and right_max

## Usage

```python
#!/usr/bin/python3

rain = __import__('0-rain').rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Output: 6

walls = []
print(rain(walls))  # Output: 0

walls = [1, 2, 3]
print(rain(walls))  # Output: 0 (no valleys to trap water)
```

## Edge Cases

The implementation handles:
- Empty lists → returns 0
- Lists with fewer than 3 elements → returns 0 (can't trap water)
- Monotonically increasing/decreasing arrays → returns 0
- Single peaks and valleys
- Complex terrain with multiple peaks and valleys

## Environment

- Ubuntu 14.04 LTS
- Python 3 (version 3.4.3)
- PEP 8 style (version 1.7.x)