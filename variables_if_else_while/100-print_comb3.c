#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
 * Description: numbers are printed in ascending order, separated by ", "
 *              only the smallest combination is printed (e.g., 01 not 10)
 * Return: Always 0 (Success)
 */
int main(void)
{
int i, j;

for (i = 0; i < 9; i++)
{
for (j = i + 1; j < 10; j++)
{
putchar(i + '0');
putchar(j + '0');

if (!(i == 8 && j == 9))
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');

return (0);
}
