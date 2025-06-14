#!/usr/bin/python3
"""Making Change"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
    coins (int[]): List of coin values in possession
    total (int): Target amount to make change for

    Returns:
    int: Fewest number of coins needed, -1 if impossible
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount and dp[amount - coin] != float('inf'):
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
