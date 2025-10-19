#include "hash_tables.h"
#include <stdlib.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: Pointer to the newly created sorted hash table, or NULL if failed
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;

ht = malloc(sizeof(shash_table_t));
if (!ht)
return (NULL);

ht->size = size;
ht->array = calloc(size, sizeof(shash_node_t *));
if (!ht->array)
{
free(ht);
return (NULL);
}

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}
