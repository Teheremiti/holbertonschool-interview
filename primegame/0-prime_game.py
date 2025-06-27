#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """
    Determine who wins the most rounds of the prime game

    Args:
    x: Number of rounds
    nums: Array of n values for each round

    Returns:
    Name of player who won most rounds, or None if tie
    """
    if not nums or x != len(nums):
        return None

    max_n = max(nums)
    if max_n < 2:
        return "Ben"

    # Sieve of Eratosthenes to find all primes up to max_n
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(max_n**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, max_n + 1, i):
                is_prime[j] = False

    # Precompute prime counts for each possible n
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i-1] + (1 if is_prime[i] else 0)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n < 2:
            ben_wins += 1
        else:
            # Number of moves = number of primes ≤ n
            moves = prime_count[n]
            if moves % 2 == 1:
                maria_wins += 1
            else:
                ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
