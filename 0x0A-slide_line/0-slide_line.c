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
	if (!line || size <= (size_t) 0)
		return (0);

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

/**
 * slide_right - function that will slide line right
 * @line: line to manipulate
 * @size: line size
 */
void slide_right(int *line, size_t size)
{
	size_t lhs, rhs;
	int i_lhs;

	lhs = rhs = size - 1;
	i_lhs = (int) lhs;
	while (i_lhs-- > 0)
	{
		if (line[rhs] == line[i_lhs] && line[i_lhs] != 0)
		{
			line[rhs] += line[i_lhs];
			line[i_lhs] = 0;
			rhs--;
		} else if (line[i_lhs] > 0)
		{
			if (line[rhs] != 0)
				rhs--;
			if ((size_t) i_lhs == rhs)
				continue;
			line[rhs] = line[i_lhs];
			line[i_lhs] = 0;
		}
	}
}

/**
 * slide_left - function that will slide line left
 * @line: line to manipulate
 * @size: line size
 */
void slide_left(int *line, size_t size)
{
	size_t lhs, rhs;

	lhs = rhs = 0;
	while (rhs++ < size)
	{
		if (line[lhs] == line[rhs] && line[rhs] != 0)
		{
			line[lhs] += line[rhs];
			line[rhs] = 0;
			lhs++;
		} else if (line[rhs] > 0)
		{
			if (line[lhs] != 0)
				lhs++;
			if (lhs == rhs)
				continue;
			line[lhs] = line[rhs];
			line[rhs] = 0;
		}
	}
}

