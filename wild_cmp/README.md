# Wildcard Comparison

This project implements a function that compares two strings with wildcard support.

## Description

The `wildcmp` function compares two strings where the second string can contain the special wildcard character `*`. The `*` can replace any string (including an empty string).

## Files

- `holberton.h` - Header file containing function prototypes
- `0-wildcmp.c` - Implementation of the wildcard comparison function

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Parameters

- `s1`: The first string to compare
- `s2`: The second string that can contain '*' wildcards

## Return Value

- Returns `1` if the strings can be considered identical
- Returns `0` otherwise

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

## Algorithm

The function uses recursion to handle wildcard matching:

1. If the pattern (s2) is empty, check if the string (s1) is also empty
2. If the current character in the pattern is '*':
   - Try matching '*' with an empty string
   - Try matching '*' with one or more characters
3. If the current character is not '*', it must match exactly
4. Continue recursively with the remaining characters

## Examples

- `wildcmp("main.c", "*.c")` returns `1` - '*' matches "main"
- `wildcmp("main.c", "m*c")` returns `1` - '*' matches "ain."
- `wildcmp("main.c", "*")` returns `1` - '*' matches entire string
- `wildcmp("main.c", "m.*c")` returns `0` - '.' doesn't match 'i'