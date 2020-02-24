#!/usr/bin/python3
"""
calculates the fewest number of operations
limited to only `Copy All` and `Paste`
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """calculates the fewest number of operations

    Keyword arguments:
    n -- number of Charaters to achieve
    """
    f = 0

    if n >= 2:
        while n > 1:
            if n % 2 == 0:
                f += 2
                n //= 2
            elif n % 3 == 0:
                f += 3
                n //= 3
            elif n % 5 == 0:
                f += 5
                n //= 5
            elif n % 7 == 0:
                f += 7
                n //= 7
            else:
                f += n
                n //= n

    return int(f)


if __name__ == "__main__":
    pass
