#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * struct hash_node_s - Node of a hash table
 * @key:  Key string (must be unique in the table)
 * @value: Value string associated with @key
 * @next: Pointer to the next node (for chaining collisions)
 */
typedef struct hash_node_s
{
char *key;
char *value;
struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size:  Number of slots in @array
 * @array: Array of pointers to the first node of each chain
 *
 * Each cell in @array points to the head of a linked list (chaining).
 */
typedef struct hash_table_s
{
unsigned long int size;
hash_node_t **array;
} hash_table_t;

/* Prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);
/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key (string)
 * @value: The value associated with the key
 * @next: Pointer to the next node in the same bucket
 * @snext: Pointer to the next node in the sorted linked list
 * @sprev: Pointer to the previous node in the sorted linked list
 */
typedef struct shash_node_s
{
    char *key;
    char *value;
    struct shash_node_s *next;
    struct shash_node_s *snext;
    struct shash_node_s *sprev;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table
 * @size: The size of the array
 * @array: An array of pointers to the first node of each bucket
 * @shead: Pointer to the first element of the sorted linked list
 * @stail: Pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);


#endif /* HASH_TABLES_H */
