#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints each element in a list_t list
 * @h: pointer to the first node of the list
 *
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	const list_t *node = h;
	size_t total = 0;

	while (node != NULL)
	{
		if (node->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", node->len, node->str);

		node = node->next;
		total++;
	}

	return (total);
}
