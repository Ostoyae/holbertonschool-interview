#include "search.h"
#include <stdio.h>

/**
 * linear_skip - search a linked list with skipping
 * @list: pointer to a linked list with skipping
 * @value: search
 * Return: pointer to found node else NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;
	size_t count;

	node = list;
	if (!list)
		return (NULL);

	if (node->n > value)
		return (NULL);
	else if (node->n == value)
		return (node);

	for (count = 0; node->next; node = node->next, count++);
	node = list;
	skip_some(&node, value, count);

	while (node)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}

/**
 * skip_some - hops through the express lane
 * @list: pointer to a linked list
 * @value: value to search for
 */
void skip_some(skiplist_t **list, int value, size_t size)
{
	skiplist_t *node;

	node = *list;

	while (node && node->express)
	{

		if (!node->index == 0)
		{
			printf("Value checked at index [%ld] = [%d]\n", node->index,
			       node->n);
			if (node->express)
				*list = node->express;
			else
				*list = node;

//			printf("\texpress idx is %d\n", node->express->index);
		}

		if (node->express && value > node->express->n)
		{
			node = node->express;
			if (!node->express)
				printf("Value found between indexes [%ld] = [%ld]\n",
				       node->index,
				       size);

			continue;
		}

		if (node->express && value < node->express->n)
		{
			printf("Value checked at index [%ld] = [%d]\n",
			       node->express->index,
			       node->express->n);
			printf("Value found between indexes [%ld] = [%ld]\n",
			       node->index,
			       node->express->index);
			*list = node;
			break;
		}


	}
}

