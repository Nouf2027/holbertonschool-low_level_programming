#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 * key:The key (string), unique in the hash table
 * value: The value associated with the key
 * next: Points to the next node in the list
 */
typedef struct hash_node_s
{
char *key;
char *value;
struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * size: The size of the array
 * array: The array of pointers to nodes
 */
typedef struct hash_table_s
{
unsigned long int size;
hash_node_t **array;
} hash_table_t;

/**
 * hash_table_create - Creates a hash table
 * size: The size of the array
 *
 * Return: Pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
