#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

bool topple_piles(int grid[3][3], int [3][3]);

bool verify_stable(int grid[3][3], int stable[3][3]);

void give(int r, int c, int grid[3][3]);

void p_grid(int grid[3][3]);

#endif
