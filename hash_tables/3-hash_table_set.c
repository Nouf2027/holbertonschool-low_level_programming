#include "hash_tables.h"

/**
 * hash_table_set - Insert or update a key/value in a hash table
 * @ht: pointer to the hash table
 * @key: key string (must not be empty)
 * @value: value string (duplicated internally)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *node, *cur;
char *value_copy;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);

for (cur = ht->array[index]; cur != NULL; cur = cur->next)
{
if (strcmp(cur->key, key) == 0)
{
value_copy = strdup(value);
if (value_copy == NULL)
return (0);
free(cur->value);
cur->value = value_copy;
return (1);
}
}

node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (0);

node->key = strdup(key);
if (node->key == NULL)
{
free(node);
return (0);
}

node->value = strdup(value);
if (node->value == NULL)
{
free(node->key);
free(node);
return (0);
}

node->next = ht->array[index];
ht->array[index] = node;

return (1);
}

