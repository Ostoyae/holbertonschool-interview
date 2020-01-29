#!/usr/bin/python3

def canUnlockAll(boxes):
    if not isinstance(boxes, list):
        return False

    n_boxes = len(boxes)
    if n_boxes is 1:
        return True
    elif n_boxes is 0 or len(boxes[0]) is 0:
        return False
    keys = boxes[0]
    visited = {k: False for k in range(n_boxes)}
    visited[0] = True

    while keys:
        keys = unlock(keys, boxes, visited)

    return True if hasAllVisited(visited) else False


def unlock(keys: list, boxes: list, visited : dict):
    for k in keys:
        if visited[k]:
            keys.remove(k)
        else:
            keys.remove(k)
            visited[k] = True
            try:
                boxes[k].remove(k)
            except ValueError:
                pass
            if len(boxes[k]) > 0:
                keys += boxes[k]

    
    return keys if len(keys) > 0 else None

def hasAllVisited(visited):
    return False if False in visited.values() else True

if __name__ == "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))

