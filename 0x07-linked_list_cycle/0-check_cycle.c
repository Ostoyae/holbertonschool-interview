#include "lists.h"

/**
 * check_cycle - check is a linked list is a cycle.
 * @list : Linked list to check
 * Return: 1 if a cycle else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;
	int toggle;

	if (!list)
		return (0);
	else if (!list->next)
		return (0);

	toggle = 0;
	slow = fast = list;

	while (fast)
	{
		toggle++;
		fast = fast->next;
		if (slow == fast)
			return (1);
		if (toggle % 2)
			slow = slow->next;
	}

	return (0);
}
