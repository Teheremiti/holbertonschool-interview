#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int *values;
	int count = 0, i;

	if (head == NULL || *head == NULL)
		return (1); /* Empty list is considered a palindrome */

	/* First pass: count the number of nodes */
	current = *head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	/* Allocate array to store values */
	values = malloc(sizeof(int) * count);
	if (values == NULL)
		return (0);

	/* Second pass: store all values in the array */
	current = *head;
	i = 0;
	while (current != NULL)
	{
		values[i] = current->n;
		current = current->next;
		i++;
	}

	/* Check if the array is a palindrome */
	for (i = 0; i < count / 2; i++)
	{
		if (values[i] != values[count - 1 - i])
		{
			free(values);
			return (0);
		}
	}

	free(values);
	return (1);
}
