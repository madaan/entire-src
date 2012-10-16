//sg
#include<stdio.h>
int FIBO_TABLE[100];
int fibo(int n)
{
if(n==0)
return 0;
if(n==1)
return 1;
if(FIBO_TABLE[n-1]==-1)
{
FIBO_TABLE[n-1]=fibo(n-1);
}
if(FIBO_TABLE[n-2]==-1)
{
FIBO_TABLE[n-2]=fibo(n-2);
}
FIBO_TABLE[n]=FIBO_TABLE[n-1]+FIBO_TABLE[n-2];
return FIBO_TABLE[n];
}
main()
{
int i;
for(i=0;i<100;i++)
FIBO_TABLE[i]=-1;
for(i=0;i<15;i++)
printf("%d\n",fibo(i));
}

