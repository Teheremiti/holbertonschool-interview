# N Queens Problem

## Description

The N queens puzzle is the challenge of placing N non-attacking queens on an N×N chessboard. This means that no two queens can be in the same row, column, or diagonal.

## Solution

This program solves the N queens problem using a backtracking algorithm that:
1. Places queens one by one in different columns
2. For each placement, checks if it's safe (no conflicts with previously placed queens)
3. If safe, proceeds to place the next queen
4. If not safe, backtracks and tries the next position
5. When all queens are placed successfully, records the solution

## Usage

```bash
./0-nqueens.py N
```

Where `N` is an integer greater than or equal to 4.

## Requirements

- N must be an integer
- N must be at least 4
- Only the `sys` module is allowed for imports
- Program must be executable
- Follows PEP 8 style guidelines

## Examples

### 4 Queens
```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

### 6 Queens
```bash
$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

## Error Handling

- **Wrong number of arguments**: Prints "Usage: nqueens N" and exits with status 1
- **N is not an integer**: Prints "N must be a number" and exits with status 1
- **N is less than 4**: Prints "N must be at least 4" and exits with status 1

## Algorithm Complexity

- **Time Complexity**: O(N!) in the worst case, though the actual performance is much better due to pruning
- **Space Complexity**: O(N) for the board representation and recursion stack

## File Structure

- `0-nqueens.py`: Main program file
- `README.md`: This documentation file
