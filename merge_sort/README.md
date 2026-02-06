Merge Sort
==========

This project implements a **top-down merge sort** for an array of integers.

### Files

- `0-merge_sort.c`: Implementation of `merge_sort`.
- `sort.h`: Header file with function prototypes.
- `print_array.c`: Helper function provided by Holberton to print arrays.
- `0-O`: Big-O time complexity of merge sort (best, average, worst).

### Algorithm

- Uses a **top-down recursive** merge sort.
- The array is split into two sub-arrays where the **left size is always less than or equal to the right**.
- The left sub-array is sorted **before** the right sub-array.
- A single auxiliary buffer is allocated once and reused during merging (only one `malloc` and one `free` call).
