#include "slide_line.h"

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
