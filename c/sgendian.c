//sg
#include<stdio.h>
main()
{
int a=1,t=0;
char * check;
check=(char *)&a;
t=*check;
if(t==0)
printf("Big Endian\n");
else
printf("Little Endian\n");
}

