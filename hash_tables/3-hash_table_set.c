#include "hash_tables.h"

/**
 * hash_table_set - add or update an element in a hash table
 * @ht: hash table
 * @key: key string (must not be empty)
 * @value: value string (will be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *tmp;
	unsigned long int idx;
	char *val_copy;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	val_copy = strdup(value);
	if (!val_copy)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	/* update existing key */
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	/* add new node at head on collision */
	node = malloc(sizeof(*node));
	if (!node)
	{
		free(val_copy);
		return (0);
	}

	node->key = strdup(key);
	if (!node->key)
	{
		free(val_copy);
		free(node);
		return (0);
	}

	node->value = val_copy;
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}
