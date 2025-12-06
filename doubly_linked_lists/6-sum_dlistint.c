#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data (n) in a dlistint_t list
 * @head: pointer to the first node in the list
 *
 * Return: sum of all n values, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *node = head;
	int total = 0;

	while (node != NULL)
	{
		total += node->n;
		node = node->next;
	}

	return (total);
}
