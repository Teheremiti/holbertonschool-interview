# Regular Expression Matching

This project implements a function that checks whether a given pattern matches a given string using basic regular expression matching.

## Description

The `regex_match` function supports a subset of regular expression functionality:
- `.` (dot) matches any single character
- `*` (asterisk) matches zero or more of the preceding character

## Files

- `regex.h` - Header file containing function prototypes
- `regex.c` - Implementation of the regex matching function
- `main.c` - Test file demonstrating various pattern matching scenarios

## Function Prototype

```c
int regex_match(char const *str, char const *pattern);
```

## Parameters

- `str`: The string to scan (can be empty, contains any ASCII except `.` and `*`)
- `pattern`: The regular expression pattern (can be empty, can contain `.` and `*`)

## Return Value

- Returns `1` if the pattern matches the string
- Returns `0` if the pattern doesn't match

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c -o regex_test
```

## Algorithm

The function uses recursion to handle pattern matching:

1. **Base case**: If pattern is empty, string must also be empty for a match
2. **Star operator**: If next character is `*`:
   - Try matching zero occurrences (advance pattern by 2)
   - Try matching one or more occurrences (advance string, keep pattern)
3. **Regular character/dot**: Current characters must match, then recurse

## Examples

| String | Pattern | Result | Explanation |
|--------|---------|--------|-------------|
| `"H"` | `"H"` | `1` | Exact match |
| `"HH"` | `"H"` | `0` | String longer than pattern |
| `"HH"` | `"H*"` | `1` | H followed by zero or more H |
| `"Holberton"` | `".*"` | `1` | Any string matches .* |
| `"Holberton"` | `"Z*H.*"` | `1` | Zero Z's, H, then any chars |
| `"Holberton"` | `"holberton"` | `0` | Case sensitive |
| `"Holberton"` | `".olberton"` | `1` | Any char + "olberton" |

## Usage

```c
#include "regex.h"

int main(void)
{
    int result;

    result = regex_match("hello", "he.*o");  // Returns 1
    result = regex_match("test", "t*est");   // Returns 1
    result = regex_match("abc", "a.c");      // Returns 1
    result = regex_match("xyz", "a*xyz");    // Returns 1

    return (0);
}
```

## Pattern Matching Rules

- **Dot (.)**: Matches exactly one character of any type
- **Asterisk (*)**: Matches zero or more of the immediately preceding character
- **Literal characters**: Must match exactly (case-sensitive)
- **Empty pattern**: Only matches empty string
- **Empty string**: Matches empty pattern or patterns that can match zero characters

## Time Complexity

- Worst case: O(2^(n+m)) where n is string length and m is pattern length
- This occurs with patterns like `a*a*a*...b` against strings like `aaaa...a`
- Average case is much better for typical patterns