#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * make_node - Creates a new hash node
 * @key: The key
 * @value: The value
 * Return: A pointer to the new node, or NULL on failure
 */
static hash_node_t *make_node(const char *key, const char *value)
{
hash_node_t *n = malloc(sizeof(*n));

if (!n)
return (NULL);

n->key = strdup(key);
n->value = strdup(value ? value : "");

if (!n->key || !n->value)
{
free(n->key);
free(n->value);
free(n);
return (NULL);
}

n->next = NULL;
return (n);
}

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int i;
hash_node_t *node, *cur;
char *cpy;

if (!ht || !key || !*key || !value || !ht->array)
return (0);

i = key_index((const unsigned char *)key, ht->size);

for (cur = ht->array[i]; cur; cur = cur->next)
if (strcmp(cur->key, key) == 0)
{
cpy = strdup(value);
if (!cpy)
return (0);
free(cur->value);
cur->value = cpy;
return (1);
}

node = make_node(key, value);
if (!node)
return (0);

node->next = ht->array[i];
ht->array[i] = node;
return (1);
}
