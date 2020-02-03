#!/usr/bin/python3


def canUnlockAll(boxes):
    if not isinstance(boxes, list):
        return False
    n_boxes = len(boxes)
    if n_boxes is 1:
        return True
    elif n_boxes is 0 or len(boxes[0]) is 0:
        return False
    key_ring = boxes[0]
    visited = {k: False for k in range(n_boxes)}
    visited[0] = True

    # while key_ring:
    #     key_ring = unlock(key_ring, boxes, visited, n_boxes)
    r_unlock(key_ring, boxes, visited, n_boxes)

    return True if has_all_visited(visited) else False


def unlock(keys: list, boxes: list, visited: dict, n_boxes: int):
    for k in keys:
        # print(keys)
        if k > n_boxes - 1 or visited[k]:
            keys.remove(k)
        else:
            b = list()
            keys.remove(k)
            visited[k] = True
            try:
                b = [i for i in boxes[k] if not visited[i]]
            except ValueError:
                pass
            keys += b

    return keys if len(keys) > 0 else None


def r_unlock(keys: list, boxes: list, visited: dict, n_boxes: int):
    if len(keys) == 0:
        return
    k, *keys = keys
    if k > n_boxes - 1 or visited[k]:
        r_unlock(keys, boxes, visited, n_boxes)
        # keys = [i for i in keys if i < n_boxes or not visited[i]]
    else:
        visited[k] = True
        b = list()
        keys = [i for i in keys if i < n_boxes or not visited.get(k)]
        try:
            b = [i for i in boxes[k] if not visited[i]]
        except ValueError:
            pass
        keys += b

    r_unlock(keys, boxes, visited, n_boxes)


def has_all_visited(visited):
    return False if False in visited.values() else True


if __name__ == "__main__":
    pass
