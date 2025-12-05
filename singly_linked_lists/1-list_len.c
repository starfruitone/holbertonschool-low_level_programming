#include "lists.h"

/**
 * list_len - counts the number of elements in a list_t list
 * @h: pointer to the first node of the list
 *
 * Return: number of elements in the list
 */
size_t list_len(const list_t *h)
{
	const list_t *node = h;
	size_t size = 0;

	while (node != NULL)
	{
		size++;
		node = node->next;
	}

	return (size);
}
