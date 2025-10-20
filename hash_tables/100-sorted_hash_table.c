#include <stdlib.h>
#include "hash_tables.h"

/**
 * shash_table_set - adds or updates an element in the sorted hash table
 * @ht: pointer to the sorted hash table
 * @key: key string (cannot be empty)
 * @value: value string (must be duplicated)
 *
 * Return: 1 if success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *node, *tmp;
char *val_copy;

if (!ht || !key || !*key || !value)
return (0);

val_copy = strdup(value);
if (!val_copy)
return (0);

index = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[index];

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

node = malloc(sizeof(shash_node_t));
if (!node)
{
free(val_copy);
return (0);
}

node->key = strdup(key);
node->value = val_copy;
node->next = ht->array[index];
ht->array[index] = node;

node->snext = NULL;
node->sprev = NULL;

if (!ht->shead)
{
ht->shead = node;
ht->stail = node;
}
else
{
tmp = ht->shead;
while (tmp && strcmp(key, tmp->key) > 0)
tmp = tmp->snext;

if (!tmp)
{
node->sprev = ht->stail;
ht->stail->snext = node;
ht->stail = node;
}
else if (tmp == ht->shead)
{
node->snext = tmp;
tmp->sprev = node;
ht->shead = node;
}
else
{
node->sprev = tmp->sprev;
node->snext = tmp;
tmp->sprev->snext = node;
tmp->sprev = node;
}
}
return (1);
}
