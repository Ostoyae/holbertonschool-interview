#include "lists.h"

listint_t *new_node(int, listint_t *);

/**
 *  inserts a number into a sorted singly linked list. 
 *  @head: linked list to perform insert on.
 *  @number: value to assign the new node.
 * 
 *  Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *node, *out_node;

    if (!head || !(*head))
    {
        *head = new_node(number, NULL); 
        return (*head);
    }

    /* if number is less than head `n`*/
    if ((*head)->n > number)
    {
        out_node = new_node(number, *head);
        if (!out_node)
            return (NULL);
        return (*head = out_node);
    }

    for (node = *head; node->next; node = node->next)
        if (node->next->n >= number)
            break;

    out_node = new_node(number, node->next);
    if (!out_node)
        return (NULL);
    node->next = out_node;

    return (out_node);
}

/**
 * create a new node with a value(`n`) and next
 * @value: value to set nodes `n` field as.
 * @next: pointer in which to set node's `next` field as.
 * 
 * Return: pointer to the new node or else NULL.
 */
listint_t *new_node(int value, listint_t *next)
{
    listint_t *node;

    node = malloc(sizeof(listint_t));
    if (!node)
        return (NULL);
    node->n = value;
    node->next = next;
    return node;
}

