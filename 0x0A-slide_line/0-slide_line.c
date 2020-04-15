#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - function that will choose the operation to run on the line.
 * @line: line to manipulate
 * @size: line size
 * @direction: int number that correlates to a directions
 * Return: 1 (SUCCESS) else 0(FAILURE)
 */
int slide_line(int *line, size_t size, int direction)
{
	switch (direction)
	{
		case LEFT:
			slide_left(line, size);
			break;
		case RIGHT:
			slide_right(line, size);
			break;
		default:
			return (0);
	}
	return (1);
}

