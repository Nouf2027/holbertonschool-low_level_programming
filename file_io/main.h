#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
ssize_t n;

n = read_textfile("Requiescat", 114);
printf("\n(printed chars: %li)\n", n);
return (0);
}
