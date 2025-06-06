# Minimum Operations

## Description

This project contains a solution to the minimum operations problem. Given a text file with a single character 'H', the challenge is to determine the minimum number of Copy All and Paste operations needed to achieve exactly n 'H' characters.

## Problem Statement

In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste. Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.

## Requirements

- Prototype: `def minOperations(n)`
- Returns an integer
- If n is impossible to achieve, return 0

## Files

- `0-minoperations.py`: Contains the `minOperations` function implementation
- `0-main.py`: Test file to verify the implementation

## Algorithm

The solution uses **prime factorization**:

1. **Key Insight**: To optimally reach n characters, we need to find the best factorization of n
2. **Strategy**: Each factor represents a sequence of Copy All followed by (factor-1) Paste operations
3. **Solution**: The minimum operations equals the sum of all prime factors of n
4. **Example**: For n=12 = 2×2×3, we need 2+2+3 = 7 operations

### Step-by-step for n=9:
```
Start: H (1 character)
Copy All → Paste → Paste: HHH (3 characters, 3 operations)
Copy All → Paste → Paste: HHHHHHHHH (9 characters, 6 operations total)
```
Since 9 = 3×3, we need 3+3 = 6 operations.

## Usage

```python
#!/usr/bin/python3

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))  # 4

n = 12
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))  # 7

n = 9
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))  # 6
```

## Environment

- Ubuntu 14.04 LTS
- Python 3 (version 3.4.3)
- PEP 8 style (version 1.7.x)