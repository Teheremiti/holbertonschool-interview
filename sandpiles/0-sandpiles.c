#include <stdio.h>

/**
 * print_grid - Print 3x3 grid.
 * @grid: 3x3 grid.
 * Return: Nothing.
 */

void print_sandpile(int grid[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * stabilize_sandpile - Stabilize a sandpile.
 * @grid: Input sandpile.
 * Return: Nothing.
 */

void stabilize_sandpile(int grid[3][3]) {
    int stable = 0;
    while (!stable) {
        int i, j;

        stable = 1;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid[i][j] > 3) {
                    stable = 0;
                    break;
                }
            }
            if (!stable)
                break;
        }
        if (!stable) {
            int i, j;

            printf("=\n");
            print_sandpile(grid);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (grid[i][j] > 3) {
                        grid[i][j] -= 4;
                        if (i > 0)
                            grid[i - 1][j]++;
                        if (i < 2)
                            grid[i + 1][j]++;
                        if (j > 0)
                            grid[i][j - 1]++;
                        if (j < 2)
                            grid[i][j + 1]++;
                    }
                }
            }
        }
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles into the first given.
 *
 * @grid1: Input sandpile.
 * @grid2: Input sandpile.
 *
 * Return: Nothing.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }
    stabilize_sandpile(grid1);
}
