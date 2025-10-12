#include <stdio.h>

/**
 * print_before_main - prints a message before main is executed
 *
 * Return: nothing
 */
void attribute ((constructor)) print_before_main(void)
{
printf("You're beat! and yet, you must allow,\n");
printf("I bore my house upon my back!\n");
}
