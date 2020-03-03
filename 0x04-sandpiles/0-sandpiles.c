#include "sandpiles.h"

/**
 * sandpiles_sum - return that sum of a set of sandpiles.
 * @grid1 : grid to do addition with.
 * @grid2  : grid to added to `grid1` and use as a stability checker.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int r, c, size;

	size = sizeof(grid1[0]) / sizeof(int);
	/* Add `grid2` to `grid1` and store sum within `grid1`*/
	for (r = 0; r < size; r++)
		for (c = 0; c < size; c++)
		{
			grid1[r][c] += grid2[r][c];
			if (grid1[r][c] <= 3)
				grid2[r][c] = 1;
			else
				grid2[r][c] = 0;
		}

	while (!verify_stable(grid1, grid2))
	{
		printf("=\n");
		p_grid(grid1);
		topple_piles(grid1, grid2);
	}

}

/**
 * topple_piles - function that will perform tine toppling of piles
 * that are deemed unstable.
 * @grid : grid to effect
 * @stable : grid use to check if a tile is or was stable.
 * Return: true if topple occured else flase
 */
bool topple_piles(int grid[3][3], int stable[3][3])
{
	int r, c, size;
	bool toppled;

	size = sizeof(grid[0]) / sizeof(int);
	toppled = false;

	for (r = 0; r < size; r++)
		for (c = 0; c < size; c++)
		{
			if (grid[r][c] > 3 && stable[r][c] == 0)
			{
				toppled = true;
				grid[r][c] -= 4;
				give(r, c, grid);
			}
		}

	verify_stable(grid, stable);

	return (toppled);
}

/**
 * give - fuction that give its neighbors (vertical and horizontal) 1 grain
 * @r : row index
 * @c : column index
 * @grid : grid to manipulate.
 */
void give(int r, int c, int grid[3][3])
{
	if (r - 1 >= 0)
		grid[r - 1][c] += 1;
	if (r + 1 <= 2)
		grid[r + 1][c] += 1;
	if (c - 1 >= 0)
		grid[r][c - 1] += 1;
	if (c + 1 <= 2)
		grid[r][c + 1] += 1;
}

/**
 * verify_stable - check if a `grid` is stable and also update `stable`
 *  matrix used to check stablility of main grid.
 * @grid : matrix to manipluate.
 * @stable : matrix use to check tiles stablility
 * Return: `True` if all tiles are stable else `False` if one tile
 * was found to be otherwise.
 */
bool verify_stable(int grid[3][3], int stable[3][3])
{
	int r, c;
	bool is_stable;

	is_stable = true;
	for (r = 0; r < 3; r++)
		for (c = 0; c < 3; c++)
		{
			if (grid[r][c] <= 3)
				stable[r][c] = 1;
			else
			{
				is_stable = false;
				stable[r][c] = 0;
			}
		}
	return (is_stable);
}

/**
 * p_grid - prints a grid.
 * @grid : matrix to print
 */
void p_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
