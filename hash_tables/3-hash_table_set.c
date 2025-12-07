#include "hash_tables.h"

/**
 * hash_table_set - add or update an element in a hash table
 * @ht: hash table
 * @key: key string (must not be NULL/empty)
 * @value: value string (must not be NULL)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *head;
	char *kdup, *vdup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	kdup = strdup(key);
	vdup = strdup(value);
	if (kdup == NULL || vdup == NULL)
	{
		free(kdup);
		free(vdup);
		return (0);
	}

	idx = key_index((const unsigned char *)kdup, ht->size);
	head = ht->array[idx];

	/* replace existing key node entirely */
	if (head && strcmp(head->key, key) == 0 && head->next == NULL)
	{
		free(head->key);
		free(head->value);
		free(head);
		head = NULL;
	}
	else if (head && strcmp(head->key, key) == 0)
	{
		hash_node_t *tmp = head->next;

		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}

	node = malloc(sizeof(*node));
	if (node == NULL)
	{
		free(kdup);
		free(vdup);
		return (0);
	}

	node->key = kdup;
	node->value = vdup;
	node->next = head;
	ht->array[idx] = node;

	return (1);
}

