#include "lists.h"


/**
 * is_palindrome - checks if a linkedlist is a palindrome
 * @head : head of a linkedlist
 * Return : 1 if palindrome else 0
 */
int is_palindrome(listint_t **head){
    listint_t *h, *t;
    int check;

    h = t = *head;
    check = 1;

    if (!head || !(*head))
        return (-1);

    if (!(*head)->next)
        return (1);

    _is_palindrome(&h, &t, &check);

   return check;

}

/**
 * _is_palindrome - recursive checker for palindrome
 * @head - pointer to left side of linkedlist
 * @tail : pointer to right side of linkedlist
 * @check : int pointer to use as checker value
 */
void _is_palindrome(listint_t **head, listint_t **tail, int *check) {
    if ((*tail)->next)
        _is_palindrome(head, &(*tail)->next, &*check);

    if (*check == 1 && (*head)->n == (*tail)->n)
    {
        *head = (*head)->next;
        return;
    }

    *check = 0;
}