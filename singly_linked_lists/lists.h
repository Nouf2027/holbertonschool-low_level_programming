#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>
/**
 * struct list_s - singly linked list node
 * @str: string (malloc'ed string)
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: node type for a singly linked list project (Holberton/ALX)
 */
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;
/* Function prototype */
size_t print_list(const list_t *h);
#endif /* LISTS_H */
