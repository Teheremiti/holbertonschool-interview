# 2D Menger Sponge

This project implements a function to draw a 2D Menger Sponge, a fractal pattern that demonstrates self-similarity at different scales.

## Files

- `0-menger.c` - Contains the main `menger()` function implementation
- `menger.h` - Header file with function prototype and necessary includes
- `0-main.c` - Example main function for testing (not required for submission)

## Function

```c
void menger(int level);
```

### Parameters
- `level`: The level of the Menger Sponge to draw (integer)

### Behavior
- If `level` is negative, the function does nothing
- If `level` is 0, draws a simple 1x1 square with `#`
- For higher levels, draws increasingly complex fractal patterns

## Algorithm

The Menger Sponge follows a recursive pattern:
- A level N sponge is a 3x3 grid of level N-1 sponges
- The center position of each 3x3 subdivision is left empty
- The size of a level N sponge is 3^N

The implementation uses a mathematical approach to determine if each position should be filled (`#`) or empty (` `) by examining the ternary representation of the coordinates.

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

Note: The `-lm` flag is required to link with the math library for the `pow()` function.

## Usage

```bash
./0-menger <level>
```

### Examples

**Level 0:**
```
#
```

**Level 1:**
```
###
# #
###
```

**Level 2:**
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

**Level 3:**
```
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
#########         #########
# ## ## #         # ## ## #
#########         #########
###   ###         ###   ###
# #   # #         # #   # #
###   ###         ###   ###
#########         #########
# ## ## #         # ## ## #
#########         #########
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
```

## Requirements

- C compiler (gcc 4.8.4 or compatible)
- Math library (`-lm` flag)
- Betty coding style compliance
- No global variables
- Maximum 5 functions per file
- All files must end with a newline

## Author

This implementation follows the Holberton School coding standards and requirements for the interview preparation project.
