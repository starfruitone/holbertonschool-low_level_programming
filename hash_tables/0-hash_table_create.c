#include "hash_tables.h"

/**
 * hash_table_create - create a new hash table
 * @size: size of the array
 *
 * Return: pointer to table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(*ht));
	if (ht == NULL)
		return (NULL);

	ht->array = malloc(size * sizeof(*(ht->array)));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;

	return (ht);
}
