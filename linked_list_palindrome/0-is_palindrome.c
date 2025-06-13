#include "lists.h"
#include <stdlib.h>

/**
 * check_palindrome_recursive - helper function to check palindrome recursively
 * @left: pointer to pointer of left node (moves forward)
 * @right: pointer to right node (moves backward via recursion)
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome_recursive(listint_t **left, listint_t *right)
{
	/* Base case: reached end of list */
	if (right == NULL)
		return (1);

	if (!check_palindrome_recursive(left, right->next))
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;

	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *left;

	if (head == NULL || *head == NULL)
		return (1); /* Empty list is considered a palindrome */

	left = *head;
	return (check_palindrome_recursive(&left, *head));
}
