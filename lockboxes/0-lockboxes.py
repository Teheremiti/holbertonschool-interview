#!/usr/bin/python3
""" Lockboxes """

def canUnlockAll(boxes):
    """
    There are n locked boxes, each numbered sequentially from 0 to n - 1.
    Each box may contain keys to the other boxes.
    Determines if all the boxes can be opened.

    Args:
        boxes (list[list[int]]): Exactly what it sounds like.

    Returns:
        boolean: True if all boxes can be opened, otherwise False.
    """
    keys = set(boxes[0])
    for i in range(1, len(boxes)):
        keys |= set(boxes[i]).union(*(set(boxes[key]) for key in boxes[i]
                                      if key < len(boxes)))
        if i not in keys:
            return False

    return True
