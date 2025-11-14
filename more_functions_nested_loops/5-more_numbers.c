#include "main.h"
/**
 * more_numbers - prints 0 to 14, ten times
 */
void more_numbers(void)
{
int line,n;
for(line=0;line<10;line++)
{
for(n=0;n<=14;n++)
{
if(n>=10)_putchar('1');
_putchar((n%10)+'0');
}
_putchar('\n');
}
}
