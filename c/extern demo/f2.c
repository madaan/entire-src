//sg
#include<stdio.h>
main()
{
extern int baseAdd;
printf("%x",baseAdd);
//extern void foo(int);
foo(8);
}
void foo(int a)
{
extern int baseAdd;
printf("\n%d\n",a);
}
