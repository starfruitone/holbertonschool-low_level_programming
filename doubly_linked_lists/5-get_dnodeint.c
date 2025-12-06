#include "lists.h"

/**
 * get_dnodeint_at_index - returns the node at a given index in a dlistint_t list
 * @head: pointer to the first node in the list
 * @index: index of the node to find, starting at 0
 *
 * Return: pointer to the node at position index, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node = head;
	unsigned int i = 0;

	while (node != NULL)
	{
		if (i == index)
			return (node);

		node = node->next;
		i++;
	}

	return (NULL);
}
