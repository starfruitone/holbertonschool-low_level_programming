#include "hash_tables.h"

/**
 * hash_table_get - retrieve the value for a given key
 * @ht: hash table
 * @key: key to look up
 *
 * Return: pointer to value string, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
