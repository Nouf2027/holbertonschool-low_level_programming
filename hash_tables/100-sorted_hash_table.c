#include <stdlib.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;

if (size == 0)
return (NULL);

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = calloc(size, sizeof(shash_node_t *));
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

ht->shead = NULL;
ht->stail = NULL;
return (ht);
}

