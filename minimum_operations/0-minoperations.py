#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """
    Calculate the minimum number of operations to get exactly n H characters.

    Args:
    n (int): Target number of H characters

    Returns:
    int: Minimum number of operations needed, or 0 if impossible.

    The strategy is to find the optimal factorization of n. Each factor
    represents a sequence of Copy All followed by (factor-1) Paste operations.
    The minimum operations equals the sum of all prime factors of n.
    """
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    # Find all prime factors and sum them
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    # If n is still greater than 1, then it's a prime factor
    if n > 1:
        operations += n

    return operations
