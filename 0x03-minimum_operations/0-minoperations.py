#!/usr/bin/python3
"""
calculates the fewest number of operations
limited to only `Copy All` and `Paste`
needed to result in exactly n H characters in the file.
"""


def minOperations(n):

    f = 0

    if n >= 2:
        while n > 1:
            if n % 7 == 0:
                f += 7
                n //= 7
            elif n % 5 == 0:
                f += 5
                n //= 5
            elif n % 3 == 0:
                f += 3
                n //= 3
            elif n % 2 == 0:
                f += 2
                n //= 2
            else:
                f += n
                n //= n

    return int(f)


def _minOperations(n):
    """calculates the fewest number of operations

    Keyword arguments:
    n -- number of Charaters to achieve
    """

    if n in [0, 1]:
        return 0

    f = 0
    while n % 2 == 0:
        n //= 2
        f += 2

    i = 2
    while i <= n:
        if n % i:
            i += 1
        else:
            f += i
            n //= i

    return f


if __name__ == "__main__":
    pass
