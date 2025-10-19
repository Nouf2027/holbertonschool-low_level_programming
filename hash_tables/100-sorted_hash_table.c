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
/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key, string
 * @value: The value corresponding to a key
 * @next: Pointer to the next node (same index)
 * @sprev: Pointer to the previous node in the sorted linked list
 * @snext: Pointer to the next node in the sorted linked list
 */
typedef struct shash_node_s
{
char *key;
char *value;
struct shash_node_s *next;
struct shash_node_s *sprev;
struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
unsigned long int size;
shash_node_t **array;
shash_node_t *shead;
shash_node_t *stail;
} shash_table_t;
#endif
