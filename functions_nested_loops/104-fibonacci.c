#include<stdio.h>
/**
*main-prints the first 98 Fibonacci numbers,starting with 1 and 2
*Return:Always 0
*/
int main(void)
{
unsigned long a=1,b=2,a_high,a_low,b_high,b_low,carry;
int i;
printf("%lu, %lu",a,b);
for(i=2;i<98;i++)
{
if(a+b<10000000000)
{
unsigned long next=a+b;
printf(", %lu",next);
a=b;
b=next;
}
else
{
if(i==2)
{
a_high=a/1000000000;
a_low=a%1000000000;
b_high=b/1000000000;
b_low=b%1000000000;
}
carry=(a_low+b_low)/1000000000;
b_low=(a_low+b_low)%1000000000;
b_high=a_high+b_high+carry;
printf(", %lu%09lu",b_high,b_low);
a_high=b_high-a_high-carry+(a_low>b_low);
a_low=b_low;
}
}
printf("\n");
return(0);
}
