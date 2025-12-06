#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - removes a node at a given position
 * @head: pointer to head pointer
 * @index: position of node to remove
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node_removed = *head;
	unsigned int i = 0;

	if (!*head)
		return (-1);

	if (index == 0)
	{
		*head = node_removed->next;
		if (*head)
			(*head)->prev = NULL;
		free(node_removed);
		return (1);
	}

	while (i < index && node_removed)
	{
		node_removed = node_removed->next;
		i++;
	}

	if (!node_removed)
		return (-1);

	if (node_removed->next)
		node_removed->next->prev = node_removed->prev;

	if (node_removed->prev)
		node_removed->prev->next = node_removed->next;

	free(node_removed);
	return (1);
}
