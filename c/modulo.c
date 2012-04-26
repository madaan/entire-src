//sg
#include<stdio.h>
int linearSearch(int * a,int n,int total)
{
int i=0;
while(i<total)
{
if((*(a+i))==n)
{
return 0;
}
i++;
}
return 1;
}
main()
{
int i=0,j=0,num,distinct
;
int a[10];
while(i<10)
{
distinct=0;
j=0;
while(j<10)
{
scanf("%d",&num);

if(linearSearch(a,(num%42),j))
{
distinct++;
}
a[j]=num%42;
j++;
}
printf("%d\n",distinct);
i++;
}
}
