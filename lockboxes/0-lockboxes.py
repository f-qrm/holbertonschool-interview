#!/usr/bin/python3
"""You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the
    other boxes"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    keys = list(boxes[0])
    open_boxes = {0}

    while keys:
        key = keys.pop()
        if key < len(boxes) and key not in open_boxes:
            keys.extend(boxes[key])
            open_boxes.add(key)
    return len(open_boxes) == len(boxes)
