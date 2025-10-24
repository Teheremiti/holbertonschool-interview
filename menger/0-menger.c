#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 *
 * If level is lower than 0, the function does nothing
 */
void menger(int level)
{
	int size, i, j, x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					printf(" ");
					break;
				}
				x /= 3;
				y /= 3;
			}
			if (x == 0 && y == 0)
				printf("#");
		}
		printf("\n");
	}
}
