#!/usr/bin/python3

"""
app for solving possible N Queen combinations for a give board size
"""

N = -1
found = []


def isSafe(board, row, col, size):
    """
    Check if a row and col coordinate is safe
    @param board: board to sample
    @param row: row coordinate
    @param col: column coordinate
    @param size: size of the board
    @return: boolean: False if Not safe else True
    """
    for i in range(row, -1, -1):
        if board[i][col] == 1:
            return False

    for r, c in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    for r, c in zip(range(row, -1, -1), range(col, size, 1)):
        if board[r][c] == 1:
            return False

    return True


def solveNQ(board, row):
    """
    Recursive N Queen Solver
    @param board: board to add propagate queens on
    @param row: row to ass a new queen to
    @return: boolean: True if valid n queen board, else False.
    """
    global N
    if row == N:
        return True

    res = False
    for col in range(0, N):
        if isSafe(board, row, col, N):
            board[row][col] = 1
            res = solveNQ(board, row + 1)

    return res


def solverPossibleNQ(size):
    """
    Entry point for Recursive NQueen solver
    @param size: size of the Board
    @return: None
    """
    global N
    global found

    if N == -1:
        N = size

    for row in range(0, N):
        board = [[0 for i in range(N)] for i in range(N)]
        board[0][row] = 1
        if solveNQ(board, 1):

            found.append(board)

    if len(found) > 0:
        for f in found:
            print_result(f, size)


def print_result(board, size):
    """
    print out each queens location per row
    @param board: board to print
    @param size: size of the board
    @return: None
    """
    out = []
    for i in range(size):
        for j in range(size):
            if board[i][j] == 1:
                out.append([i, j])
    print(out)


if __name__ == "__main__":
    import sys

    if len(sys.argv) >= 2:
        n = int(sys.argv[1])
        solverPossibleNQ(n)
