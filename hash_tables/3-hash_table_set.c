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

	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			free(head->value);
			head->value = vdup;
			free(kdup);
			return (1);
		}
		head = head->next;
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
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}

