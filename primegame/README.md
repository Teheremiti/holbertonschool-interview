# Prime Game

## Description

Maria and Ben are playing a competitive game involving prime numbers. This project implements a solution to determine the winner when they play multiple rounds of this strategic game.

## Game Rules

1. **Setup**: Given a set of consecutive integers starting from 1 up to and including `n`
2. **Gameplay**: Players take turns choosing a prime number from the set
3. **Elimination**: When a prime is chosen, that number and ALL its multiples are removed from the set
4. **Win Condition**: The player who cannot make a move (no primes left) loses the round
5. **Turn Order**: Maria always goes first
6. **Strategy**: Both players play optimally

## Problem Statement

Given `x` rounds of the game where `n` may be different for each round, determine who wins the most rounds overall.

### Function Prototype
```python
def isWinner(x, nums)
```

**Parameters:**
- `x`: Number of rounds to play
- `nums`: Array of `n` values, where each value represents the upper limit for that round

**Returns:**
- `"Maria"`: If Maria wins the most rounds
- `"Ben"`: If Ben wins the most rounds
- `None`: If there's a tie

**Constraints:**
- `n` and `x` will not be larger than 10,000
- No external packages can be imported

## Example

```python
x = 3
nums = [4, 5, 1]

# Round 1: n = 4, set = [1, 2, 3, 4]
# Maria picks 2 → removes 2, 4 → remaining: [1, 3]
# Ben picks 3 → removes 3 → remaining: [1]
# Maria cannot move → Ben wins

# Round 2: n = 5, set = [1, 2, 3, 4, 5]
# Maria picks 2 → removes 2, 4 → remaining: [1, 3, 5]
# Ben picks 3 → removes 3 → remaining: [1, 5]
# Maria picks 5 → removes 5 → remaining: [1]
# Ben cannot move → Maria wins

# Round 3: n = 1, set = [1]
# Maria cannot move (1 is not prime) → Ben wins

# Result: Ben wins 2 rounds, Maria wins 1 round
# Winner: Ben
```

## Algorithm

The solution uses the following approach:

1. **Prime Generation**: Uses the Sieve of Eratosthenes to efficiently find all prime numbers up to the maximum `n`
2. **Game Simulation**: For each round, simulates the optimal play by:
   - Tracking available numbers in the set
   - Counting the total number of moves possible
   - Determining winner based on parity (odd moves = Maria wins, even moves = Ben wins)
3. **Winner Determination**: Compares wins across all rounds

## Usage

```python
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner

# Test case
print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
# Output: Winner: Ben
```

## Files

- `0-prime_game.py`: Main implementation of the `isWinner` function

## Key Insights

- The game's outcome depends on the total number of prime-elimination moves
- Since Maria goes first, she wins if the total moves is odd, Ben wins if even
- The optimal strategy is simply to make any available move (since all moves are forced)
- Using the Sieve of Eratosthenes optimizes prime detection for multiple rounds

## Time Complexity

- **Prime generation**: O(n log log n) using Sieve of Eratosthenes
- **Game simulation**: O(n²) per round in worst case
- **Overall**: O(max(nums) log log max(nums) + x × max(nums)²)

## Space Complexity

O(max(nums)) for storing prime flags and availability tracking.