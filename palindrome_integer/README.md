# Palindrome Integer

A C implementation to check if an unsigned long integer is a palindrome.

## Overview

This project implements a function that determines whether a given unsigned long integer is a palindrome (reads the same forwards and backwards). The solution uses an integer reversal algorithm to compare the original number with its reversed version.

## Files

| File | Description |
|------|-------------|
| `palindrome.h` | Header file containing function prototypes |
| `0-is_palindrome.c` | Implementation of the palindrome checking function |
| `0-main.c` | Test program with command-line interface |

## Function Prototype

```c
int is_palindrome(unsigned long n);
```

**Parameters:**
- `n`: The unsigned long integer to check

**Return Value:**
- `1` if the number is a palindrome
- `0` if the number is not a palindrome

## Algorithm

The function uses a digit reversal approach:

1. Store the original number
2. Extract digits from right to left using modulo and division operations
3. Build the reversed number by multiplying the current reversed value by 10 and adding the extracted digit
4. Compare the original number with the reversed number

```c
while (n > 0)
{
    reversed = reversed * 10 + n % 10;
    n /= 10;
}
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-is_palindrome.c -o palindrome
```

## Usage

```bash
./palindrome <number>
```

**Examples:**
```bash
./palindrome 121        # Output: 121 is a palindrome.
./palindrome 1234       # Output: 1234 is not a palindrome.
./palindrome 0          # Output: 0 is a palindrome.
./palindrome 1          # Output: 1 is a palindrome.
```

## Test Cases

### Valid Palindromes
- `0` - Single digit zero
- `1`, `2`, `9` - Any single digit
- `11`, `22`, `99` - Two identical digits
- `121`, `131`, `191` - Three digit palindromes
- `1221`, `1331`, `9999` - Four digit palindromes
- `12321`, `54345` - Five digit palindromes

### Non-Palindromes
- `10`, `100`, `1000` - Numbers with trailing zeros
- `123`, `1234` - Sequential numbers
- `1211`, `1331` - Numbers that start/end the same but aren't palindromes

### Edge Cases
- `0` - Zero (considered a palindrome)
- Single digits `1-9` - All single digits are palindromes
- Large numbers approaching `ULONG_MAX`

## Limitations and Edge Cases

### Integer Overflow Risk
⚠️ **Critical Limitation**: The current implementation may suffer from integer overflow when processing very large numbers.

**Problem:** During the reversal process, the line:
```c
reversed = reversed * 10 + n % 10;
```
Can cause `reversed` to exceed `ULONG_MAX`, leading to:
- Incorrect palindrome detection
- Silent wraparound behavior
- Unpredictable results

**Affected Range:** Numbers where the reversed value would exceed `ULONG_MAX` (18,446,744,073,709,551,615 on 64-bit systems).

### Input Processing Limitations
- The main function uses `atol()` which limits input to `LONG_MAX`
- Negative inputs get converted to large unsigned values
- Numbers larger than system limits may be truncated

### Example of Potential Issues
```bash
./palindrome 18446744073709551615  # May not work as expected due to atol() limits
./palindrome -1                    # Converts to ULONG_MAX
```

## Performance

- **Time Complexity:** O(log n) where n is the input number (proportional to number of digits)
- **Space Complexity:** O(1) - uses constant extra space

## Robustness Improvements

For production use, consider implementing:

1. **Overflow Detection:**
   ```c
   if (reversed > (ULONG_MAX - n % 10) / 10) {
       // Handle overflow case
       return 0;
   }
   ```

2. **Alternative Approaches:**
   - String-based comparison (convert to string, reverse, compare)
   - Half-number comparison (only reverse half the digits)
   - Mathematical bounds checking before reversal

## Standards Compliance

- Compiled with strict flags: `-Wall -Werror -Wextra -pedantic`
- Follows Betty coding style guidelines
- ANSI C compatible

## Author

Holberton School Interview Preparation - Palindrome Integer Project

## License

This project is part of the Holberton School curriculum.