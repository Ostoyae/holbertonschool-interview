#!/usr/bin/python3
"""
source for rain method
"""


def rain(walls):
    """
    calculate water retention.
    @param walls: walls to check
    @return: int
    """
    if walls is None or len(walls) == 0:
        return 0

    s = sum(walls[1:-1])
    return s


if __name__ == "__main__":
    pass
