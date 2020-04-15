#ifndef INTERVIEW_SLIDE_LINE_H
#define INTERVIEW_SLIDE_LINE_H

#include <stdbool.h>
#include <stdlib.h>


#define SLIDE_LEFT  0
#define SLIDE_RIGHT  1

int slide_line(int *line, size_t size, int direction);

void slide_right(int *line, size_t size);
void slide_left(int *line, size_t size);

/**
 * enum Dir - Directions for sliding.
 * @LEFT: int 0 direction left
 * @RIGHT: int 1 direction right
 * @UP: int 2 direction UP (not implemented yet)
 * @DOWN: int 2 direction DOWN (not implemented yet)
 */
enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

#endif
