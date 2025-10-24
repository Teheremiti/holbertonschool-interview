#!/usr/bin/python3
"""
N Queens Problem Solver

This program solves the N queens puzzle by placing N non-attacking queens
on an N×N chessboard using backtracking algorithm.
"""

import sys


def is_safe(board, row, col, n):
    """
    Check if it's safe to place a queen at board[row][col]

    Args:
        board: Current board state (list of queen positions)
        row: Row to check
        col: Column to check
        n: Board size

    Returns:
        bool: True if safe, False otherwise
    """
    # Check if any queen in the same column
    for i in range(row):
        if board[i] == col:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if board[i] == j:
            return False

    # Check upper diagonal on right side
    for i, j in zip(range(row-1, -1, -1), range(col+1, n)):
        if board[i] == j:
            return False

    return True


def solve_nqueens(board, row, n, solutions):
    """
    Solve N queens using backtracking

    Args:
        board: Current board state
        row: Current row being processed
        n: Board size
        solutions: List to store all solutions
    """
    if row == n:
        # All queens placed successfully, add solution
        solution = []
        for i in range(n):
            solution.append([i, board[i]])
        solutions.append(solution)
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col
            solve_nqueens(board, row + 1, n, solutions)
            board[row] = -1  # Backtrack


def print_solutions(n):
    """
    Print all solutions for N queens problem

    Args:
        n: Board size (number of queens)
    """
    board = [-1] * n
    solutions = []
    solve_nqueens(board, 0, n, solutions)

    for solution in solutions:
        print(solution)


def main():
    """Main function to handle command line arguments and solve N queens"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    print_solutions(n)


if __name__ == "__main__":
    main()
