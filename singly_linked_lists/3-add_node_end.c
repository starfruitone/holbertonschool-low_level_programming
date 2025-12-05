#include <string.h>
#include "lists.h"

/**
 * add_node_end - addds a new node at the end of a list_t list
 * @head: address of a pointer to the first node
 * @str: string to store in the new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *last;
	size_t len = 0;

	if (str == NULL || head == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (str[len] != '\0')
		len++;

	new_node->len = len;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	return (new_node);
}
