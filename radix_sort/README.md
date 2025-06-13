# Radix Sort

This project implements the LSD (Least Significant Digit) radix sort algorithm in C.

## Description

Radix sort is a non-comparative sorting algorithm that sorts integers by processing individual digits. The LSD radix sort algorithm processes digits from right to left (least significant to most significant).

## Files

- `sort.h` - Header file containing function prototypes
- `0-radix_sort.c` - Implementation of the radix sort algorithm
- `print_array.c` - Helper function to print arrays (provided)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Usage

The `radix_sort` function sorts an array of integers in ascending order and prints the array after each digit position is processed.

```c
void radix_sort(int *array, size_t size);
```

## Algorithm

1. Find the maximum number in the array to determine the number of digits
2. For each digit position (starting from least significant):
   - Use counting sort to sort the array based on the current digit
   - Print the array after sorting
3. Repeat until all digit positions have been processed

## Complexity

- Time Complexity: O(d * (n + k)) where d is the number of digits, n is the number of elements, and k is the range of digits (0-9)
- Space Complexity: O(n + k)