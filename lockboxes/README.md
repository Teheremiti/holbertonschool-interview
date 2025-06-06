# Lockboxes

## Description

This project contains a solution to the lockboxes problem. The challenge is to determine if all boxes can be opened given that you start with the first box unlocked and each box may contain keys to other boxes.

## Problem Statement

You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

## Requirements

- Prototype: `def canUnlockAll(boxes)`
- `boxes` is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box `boxes[0]` is unlocked
- Return `True` if all boxes can be opened, else return `False`

## Files

- `0-lockboxes.py`: Contains the `canUnlockAll` function implementation

## Algorithm

The solution uses a breadth-first search approach:

1. Start with box 0 (initially unlocked)
2. Keep track of unlocked boxes using a set
3. Use a queue to process boxes and find their keys
4. For each unlocked box, examine its keys
5. Unlock new boxes if valid keys are found
6. Continue until no more boxes can be unlocked
7. Return `True` if all boxes are unlocked, `False` otherwise

## Usage

```python
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Environment

- Ubuntu 14.04 LTS
- Python 3 (version 3.4.3)
- PEP 8 style (version 1.7.x)