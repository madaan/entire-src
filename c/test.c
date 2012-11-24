#include<stdio.h>
#include<string.h>
#define i 20
int main()
{
printf("%d..",i);
fun();
printf("%d",i);

char str[]="S65AB";
printf("\n%d", sizeof(str));}
void fun()
{
#undef i
#define i 30
}
