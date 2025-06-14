# Making Change

This project contains a function to determine the fewest number of coins needed to make a given amount total.

## Description

The `makeChange` function solves the classic coin change problem using dynamic programming. Given:
- A list of coin denominations (with infinite supply of each)
- A target total amount

The function returns the minimum number of coins needed to make that total, or -1 if impossible.

## Function Signature

```python
def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (int[]): List of coin values in possession
        total (int): Target amount to make change for

    Returns:
        int: Fewest number of coins needed, -1 if impossible
    """
```

## Algorithm

Uses bottom-up dynamic programming:
1. Create DP array where `dp[i]` = minimum coins needed for amount `i`
2. Initialize `dp[0] = 0` (0 coins needed for amount 0)
3. For each amount from 1 to total:
   - Try each coin denomination
   - Update `dp[amount] = min(dp[amount], dp[amount - coin] + 1)`
4. Return `dp[total]` or -1 if impossible

**Time Complexity**: O(total × number of coins)
**Space Complexity**: O(total)

## Usage

```python
#!/usr/bin/python3
makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))    # Output: 7
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Output: -1
```

## Edge Cases

- `total <= 0`: Returns 0
- No coins provided: Returns -1
- Impossible to make total: Returns -1
- Coins larger than total: Uses smaller denominations

## Files

- `0-making_change.py`: Contains the main function implementation
- `README.md`: This documentation file