#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees the grid passed in
 * @grid:Pointer to grid pointer
 * @height:Number of grid rows
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
