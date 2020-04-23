#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * menger - does sponge things
 * @level: detail level for the sponge
 */
void menger(int level)
{
	char **sponge;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	level = (int) pow(3, level);


	sponge = generate_sponge(level);

	print_sponge(sponge, level);

}

/**
 * generate_sponge - creates a array
 * @level: size
 * Return: array
 */
char **generate_sponge(int level)
{
	char **sponge;
	int i;


	sponge = malloc(sizeof(char *) * level + 1);
	sponge[level] = '\0';

	for (i = 0; i < level; i++)
	{
		sponge[i] = malloc(sizeof(char) * level + 1);
		memset(sponge[i], '#', level);
		sponge[i][level] = '\0';
	}

	return (sponge);
}

/**
 * print_sponge - prints a sponge
 * @sponge: sponge to print
 * @level: size
 */
void print_sponge(char **sponge, int level)
{
	size_t i, j;

	for (i = 0; i < level; i++)
	{
		for (j = 0; j < level; j++)
		{
			putchar(sponge[i][j]);
		}
		putchar('\n');
	}

}
