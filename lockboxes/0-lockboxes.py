#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened.

    Args:
    boxes (list[]): A list where each element is a list of keys contained in
    that box. Box i contains keys that can open other boxes.

    Returns:
    bool: True if all boxes can be opened, False otherwise.

    The first box (boxes[0]) is always unlocked. A key with the same number
    as a box opens that box. Keys can be positive integers and there can be
    keys that don't correspond to any box.
    """
    if not boxes:
        return True

    n = len(boxes)
    unlocked = set([0])
    keys_to_check = [0]

    while keys_to_check:
        current_box = keys_to_check.pop(0)
        for key in boxes[current_box]:
            if 0 <= key < n and key not in unlocked:
                unlocked.add(key)
                keys_to_check.append(key)

    return len(unlocked) == n
